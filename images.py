#!/usr/bin/env python
import numpy as np
from tqdm import tqdm
import math
        
# IMAGE_SIZE = 13
# DISCRETIZATION = 0.1

IMAGE_SIZE = 101
DISCRETIZATION = 0.01

class JetImage(object):
    def __init__(self, gentype, pt, eta, phi, et):
        self.gentype = int(gentype)
        self.pt = float(pt)
        self.eta = float(eta)
        self.phi = float(phi)
        self.et = float(et)

        self.pfcands = []

        self.have_centered = False
        self.have_made_image = False
        self.image = None

    def add_pfcandstr(self,pfs):
        pfcand = map(float, pfs.split(","))
        self.pfcands.append(pfcand)

    def close_pfcands(self):
        self.pfcands = np.array(self.pfcands)

    def get_pfcands(self):
        return self.pfcands

    def get_npfcands(self):
        return len(self.pfcands)

    def process_pfcands(self):
        if self.have_centered: return

        self.pfcands[:,1] -= self.eta
        self.pfcands[:,1] //= DISCRETIZATION

        self.pfcands[:,2] -= self.phi
        # self.pfcands[:,2][self.pfcands[:,2] >  3.14159] -= 2.*3.14159
        # self.pfcands[:,2][self.pfcands[:,2] < -3.14159] += 2.*3.14159
        self.pfcands[:,2][self.pfcands[:,2] >  math.pi] -= 2.*math.pi
        self.pfcands[:,2][self.pfcands[:,2] < -math.pi] += 2.*math.pi
        self.pfcands[:,2] //= DISCRETIZATION

        self.have_centered = True

    def get_maxwidth(self):
        return int(np.max(jet.get_pfcands()[:,1]) - np.min(jet.get_pfcands()[:,1]))

    def get_maxheight(self):
        return int(np.max(jet.get_pfcands()[:,2]) - np.min(jet.get_pfcands()[:,2]))

    def get_dimensions(self):
        return (self.get_maxwidth(), self.get_maxheight())

    def get_image(self):
        if self.have_made_image: return self.image

        pfcs = self.pfcands

        image_half = (IMAGE_SIZE - 1)//2

        self.image = np.zeros((IMAGE_SIZE,IMAGE_SIZE))
        for pfc in pfcs:
            ieta, iphi = int(pfc[1]), int(pfc[2])
            if abs(ieta) > image_half: continue
            if abs(iphi) > image_half: continue
            self.image[(ieta+image_half,iphi+image_half)] += pfc[3]

        # for L2 norm
        norm = np.sqrt(np.sum(self.image*self.image))
        self.image /= norm

        self.have_made_image = True
        return self.image
        

data_b = np.zeros((IMAGE_SIZE,IMAGE_SIZE))
data_nonb = np.zeros((IMAGE_SIZE,IMAGE_SIZE))

bs = []
nonbs = []
nimgs = 0

fname = "forImages.txt"
with open(fname, "r") as fhin:
    cnt = 0
    for line in tqdm(fhin):
        cnt += 1
        line = line.strip()
        if not line: continue
        parts = line.split()
        jet = JetImage(*parts[:5])
        for pfs in parts[5:]:
            jet.add_pfcandstr(pfs)
        jet.close_pfcands()
        jet.process_pfcands()

        # data.append(jet)
        if cnt > 300000: break
        # if cnt > 10: break

        img = jet.get_image()
        if jet.gentype == 2:
            data_b += img
            # bs.append(img)
        else:
            data_nonb += img
            # nonbs.append(img)
        # print jet.get_npfcands()
        nimgs += 1

        # break
        # w, h = jet.get_dimensions()
        # print w,h
        # if h > 55:
        #     print jet.get_pfcands()
        #     break

import matplotlib.pyplot as plt
from matplotlib.colors import LogNorm

imgidx = 1
for thing in bs:
    print "B:", imgidx
    plt.matshow(thing, fignum=imgidx, norm=LogNorm())
    imgidx += 1
for thing in nonbs:
    print "NonB:", imgidx
    plt.matshow(thing, fignum=imgidx, norm=LogNorm())
    imgidx += 1

plt.matshow(data_b/nimgs, fignum=1, norm=LogNorm(), cmap=plt.get_cmap("inferno"))
plt.title("b")
plt.colorbar()
plt.matshow(data_nonb/nimgs, fignum=2, norm=LogNorm(), cmap=plt.get_cmap("inferno"))
plt.title("non-b")
plt.colorbar()


plt.show()


# import pickle
# pickle.dump(data, open("out.pkl","w"))
