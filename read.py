#!/usr/bin/env python
import numpy as np
from tqdm import tqdm
import math
import ROOT as r


JET_SIZE = 0.8
DISCRETIZATION = 0.10

IMAGE_SIZE = int(JET_SIZE/DISCRETIZATION) + 2
print "IMAGE_SIZE:",IMAGE_SIZE

class JetImage(object):
    def __init__(self, gentype, pt, eta, phi, disc):
        self.gentype = int(gentype)
        self.pt = float(pt)
        self.eta = float(eta)
        self.phi = float(phi)
        self.disc = float(disc)

        self.pftypes = []
        self.pfetas = []
        self.pfphis = []
        self.pfets = []

        self.pfcands = []


        self.have_centered = False
        self.have_made_image = False
        self.image = None

    def close_pfcands(self):
        self.pfcands = zip(self.pftypes,self.pfetas,self.pfphis, self.pfets)
        self.pfcands = np.array(self.pfcands, dtype=np.float32)

    def get_pfcands(self):
        return self.pfcands

    def get_npfcands(self):
        return len(self.pfcands)

    def process_pfcands(self):
        if self.have_centered: return

        self.close_pfcands()

        self.pfcands[:,1] -= self.eta
        self.pfcands[:,1] //= DISCRETIZATION

        self.pfcands[:,2] -= self.phi
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


if __name__ == "__main__":

    ch = r.TChain("t")
    ch.Add("hists_both.root")

    xdata = []
    ydata = []

    for event in tqdm(ch):

        jet = JetImage(ch.jettype, ch.jetpt, ch.jeteta, ch.jetphi, ch.jetcsvdisc)
        jet.pfetas = list(ch.pfceta)
        jet.pfphis = list(ch.pfcphi)
        jet.pfets = list(ch.pfcet)
        jet.pftypes = list(ch.pfctype)
        jet.process_pfcands()

        xdata.append(jet.get_image())
        ydata.append([jet.gentype, jet.disc, jet.pt, jet.eta])

    np.array(xdata, dtype=np.float32).dump("dump_xdata_new.npa")
    np.array(ydata, dtype=np.float32).dump("dump_ydata_new.npa")
