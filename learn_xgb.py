#!/usr/bin/env python
import numpy as np
from tqdm import tqdm
from sklearn.model_selection import train_test_split
from sklearn import metrics
import sys

import xgboost as xgb

xdata = np.load("dump_xdata.npa")
ydata = np.load("dump_ydata.npa")

discs = ydata[:,1]
xdata = xdata.reshape(xdata.shape[0], xdata.shape[1]**2)
ydata[:,0][ydata[:,0] < 1.5] = 0
ydata[:,0][ydata[:,0] > 1.5] = 1
width = xdata.shape[1]

add_disc = True
if add_disc:
    discs[discs < 0] = 0
    xdata = np.c_[discs.T, xdata]

X_train, X_test, y_train_all, y_test_all = train_test_split(xdata, ydata, test_size=0.5, random_state=42)
y_train = y_train_all[:,0]
y_test = y_test_all[:,0]
disc_test = y_test_all[:,1]
pt_test = y_test_all[:,2]

dtrain = xgb.DMatrix( X_train, label=y_train)
dtest = xgb.DMatrix( X_test, label=y_test)
evallist  = [(dtest,'eval'), (dtrain,'train')]
num_round = 10
param = {'max_depth':3, 'eta':1, 'silent':1, 'objective':'binary:logistic' }
param['nthread'] = 4
param['eval_metric'] = 'auc'

bst = xgb.train( param.items(), dtrain, num_round, evallist )
y_pred = bst.predict(dtest)

fpr, tpr, thresholds = metrics.roc_curve(y_test, y_pred)
roc_auc = metrics.auc(fpr, tpr)
fpr_disc, tpr_disc, thresholds_disc = metrics.roc_curve(y_test, disc_test)
roc_auc_disc = metrics.auc(fpr_disc, tpr_disc)

csv_threshold = 0.8484
first_idx = np.nonzero(fpr>0.1)[0][0]
xgb_wp = thresholds[first_idx]
xgb_wp_eff = tpr[first_idx]

print """
With XGB and 10% mistag rate, the discriminant threshold 
is {0:.3f} and the b-tagging efficiency is {1:.3f}
""".format(xgb_wp,xgb_wp_eff)

import ROOT as r
import Software.pyRootPlotMaker.pyRootPlotMaker as ppm
os.system("mkdir -p plots")
d_hists = {}
d_hists["h_genb"] = r.TH1F("h_genb", "h_genb", 50, 0, 600)
d_hists["h_genbtagged"] = r.TH1F("h_genbtagged", "h_genbtagged", 50, 0, 600)
d_hists["h_genbtaggedxgb"] = r.TH1F("h_genbtaggedxgb", "h_genbtaggedxgb", 50, 0, 600)
d_hists["h_genudsg"] = r.TH1F("h_genudsg", "h_genudsg", 50, 0, 600)
d_hists["h_genudsgtagged"] = r.TH1F("h_genudsgtagged", "h_genudsgtagged", 50, 0, 600)
for pt in pt_test[y_test > 0.5]:
    d_hists["h_genb"].Fill(pt)
for pt in pt_test[(disc_test>csv_threshold) & (y_test>0.5)]:
    d_hists["h_genbtagged"].Fill(pt)
for pt in pt_test[(y_pred>xgb_wp) & (y_test>0.5)]:
    d_hists["h_genbtaggedxgb"].Fill(pt)
map(lambda x: x.Sumw2(), d_hists.values())
map(lambda x: x.SetMarkerSize(3.0), d_hists.values())
map(lambda x: x.SetLineWidth(3), d_hists.values())
ppm.plotComparison(d_hists["h_genb"],d_hists["h_genbtagged"],title="b-tag eff [CSVv2]",h1Title="gen b",h2Title="gen b + btagged",saveAs="plots/btageff_csv.pdf",xAxisTitle="p_{T}", ratioTitle="eff.", ratioRange=[0.2,1.0])
ppm.plotComparison(d_hists["h_genb"],d_hists["h_genbtaggedxgb"],title="b-tag eff [XGB]",h1Title="gen b",h2Title="gen b + btagged",saveAs="plots/btageff_xgb.pdf",xAxisTitle="p_{T}", ratioTitle="eff.", ratioRange=[0.2,1.0])

import matplotlib.pyplot as plt
plt.figure()
plt.plot(fpr, tpr, color='darkorange', lw=2, label='XGB (area = %0.2f)' % roc_auc)
plt.plot(fpr_disc, tpr_disc, color='red', lw=2, label='CSVv2 (area = %0.2f)' % roc_auc_disc)
plt.plot([0, 1], [0, 1], color='navy', lw=2, linestyle='--')
plt.xlim([0.0, 1.0])
plt.ylim([0.0, 1.05])
plt.xlabel('Mistag')
plt.ylabel('Signal Efficiency')
plt.title('ROC')
plt.plot([0.1], [0.65], 'or', label='CSVv2 (0.1,0.65)')
plt.plot([0.1], [0.70], 'ob', label='DeepCSV (0.1,0.70)')
plt.legend(loc="lower right", numpoints=1)
plt.draw()
plt.pause(1)
raw_input()
plt.close()
