#pragma GCC diagnostic ignored "-Wsign-compare"

#include "TFile.h"
#include "TTree.h"
#include "TCut.h"
#include "TColor.h"
#include "TCanvas.h"
#include "TH2F.h"
#include "TH1.h"
#include "TChain.h"
#include "TLorentzVector.h"
#include "Math/VectorUtil.h"

#include "CMS3.h"

using namespace std;
using namespace tas;


bool idIsLep(int id) {
    id = abs(id);
    return (id == 11 || id == 13 || id == 15);
}
bool idIsGamma(int id) {
  return (abs(id) == 22);
}
bool idIsCharged(int id) {
  return (abs(id) == 211 || abs(id) < 4);
}
bool idIsKaon(int id) {
  return (abs(id) == 130);
}

int ScanChain(TChain *ch, TString fname="hists.root"){

    TFile *f1 = new TFile(fname, "RECREATE");
    TH1F * h_met = new TH1F("met", "met", 50, 0, 300);

    TH1F * h_mindr = new TH1F("mindr", "mindr", 50, 0, 0.4);
    TH1F * h_absid = new TH1F("absid", "absid", 25, 0, 25);

    TH1F * h_genb = new TH1F("h_genb", "h_genb", 50, 0, 600);
    TH1F * h_genc = new TH1F("h_genc", "h_genc", 50, 0, 600);
    TH1F * h_genudsg = new TH1F("h_genudsg", "h_genudsg", 50, 0, 600);

    TH1F * h_genbtagged = new TH1F("h_genbtagged", "h_genbtagged", 50, 0, 600);
    TH1F * h_genctagged = new TH1F("h_genctagged", "h_genctagged", 50, 0, 600);
    TH1F * h_genudsgtagged = new TH1F("h_genudsgtagged", "h_genudsgtagged", 50, 0, 600);

    TH1F * h_npfcands = new TH1F("h_npfcands", "h_npfcands", 50, 0, 50);
    TH1F * h_npfcands_lep = new TH1F("h_npfcands_lep", "h_npfcands_lep", 50, 0, 50);
    TH1F * h_npfcands_gamma = new TH1F("h_npfcands_gamma", "h_npfcands_gamma", 50, 0, 50);
    TH1F * h_npfcands_charged = new TH1F("h_npfcands_charged", "h_npfcands_charged", 50, 0, 50);
    TH1F * h_npfcands_kaon = new TH1F("h_npfcands_kaon", "h_npfcands_kaon", 50, 0, 50);
    TH1F * h_npfcands_other = new TH1F("h_npfcands_other", "h_npfcands_other", 50, 0, 50);

    TH1F * h_e = new TH1F("h_e", "h_e", 50, 0, 600);
    TH1F * h_pt = new TH1F("h_pt", "h_pt", 50, 0, 600);
    TH1F * h_eta = new TH1F("h_eta", "h_eta", 50, -2.6, 2.6);
    TH1F *h_pileup = new TH1F("h_pileup", "h_pileup", 50, -1., 1.1);
    TH1F *h_chf = new TH1F("h_chf", "h_chf", 50, 0., 1.1);
    TH1F *h_nhf = new TH1F("h_nhf", "h_nhf", 50, 0., 1.1);
    TH1F *h_cef = new TH1F("h_cef", "h_cef", 50, 0., 1.1);
    TH1F *h_nef = new TH1F("h_nef", "h_nef", 50, 0., 1.1);

    TH1F *h_pfcandse_jete = new TH1F("h_pfcandse_jete", "h_pfcandse_jete", 50, 0., 2.0);

    TH1F *h_dxy_b = new TH1F("h_dxy_b", "h_dxy_b", 50, -0.5, 0.5);
    TH1F *h_dxy_nonb = new TH1F("h_dxy_nonb", "h_dxy_nonb", 50, -0.5, 0.5);
    TH1F *h_dz_b = new TH1F("h_dz_b", "h_dz_b", 50, -0.5, 0.5);
    TH1F *h_dz_nonb = new TH1F("h_dz_nonb", "h_dz_nonb", 50, -0.5, 0.5);

    TH1F *h_dxybig_b = new TH1F("h_dxybig_b", "h_dxybig_b", 50, 0,50);
    TH1F *h_dxybig_nonb = new TH1F("h_dxybig_nonb", "h_dxybig_nonb", 50, 0,50);
    TH1F *h_dzbig_b = new TH1F("h_dzbig_b", "h_dzbig_b", 50, 0,50);
    TH1F *h_dzbig_nonb = new TH1F("h_dzbig_nonb", "h_dzbig_nonb", 50, 0,50);


    float pt = 0, eta = 0, phi = 0;
    bool is_b = false;
    bool is_c = false;
    bool is_udsg = false;
    int jetpflav = -1;
    int jethflav = -1;
    int jettype = -1;
    float csvdisc = -1;
    std::vector<float> pfcphi;
    std::vector<float> pfceta;
    std::vector<float> pfcet;
    std::vector<int> pfctype;
    std::vector<float> pfcdz;
    std::vector<float> pfcdxy;
    std::vector<float> pfcdzError;
    std::vector<float> pfcdxyError;

    // float pfcphi[MAXNPFCANDS];
    // TTree
    TLorentzVector* jetp4 = new TLorentzVector();
    TLorentzVector* genp4 = new TLorentzVector();
    TTree *t = new TTree("t", "Events");
    t->Branch("jetpt", &pt, "jetpt/F");
    t->Branch("jeteta", &eta, "jeteta/F");
    t->Branch("jetphi", &phi, "jetphi/F");
    t->Branch("jetp4", "TLorentzVector", &jetp4);
    // t->Branch("genp4", "TLorentzVector", &genp4);
    t->Branch("jethflav", &jethflav, "jethtflav/I");
    t->Branch("jetpflav", &jetpflav, "jetptflav/I");
    t->Branch("jettype", &jettype, "jettype/I");
    t->Branch("jetcsvdisc", &csvdisc, "jetcsvdisc/F");

    t->Branch("isb", &is_b, "is_b/b");
    t->Branch("isc", &is_c, "is_c/b");
    t->Branch("isudsg", &is_udsg, "is_udsg/b");

    t->Branch("pfcphi", &pfcphi);
    t->Branch("pfceta", &pfceta);
    t->Branch("pfcet", &pfcet);
    t->Branch("pfctype", &pfctype);
    t->Branch("pfcdz", &pfcdz);
    t->Branch("pfcdxy", &pfcdxy);
    t->Branch("pfcdzError", &pfcdzError);
    t->Branch("pfcdxyError", &pfcdxyError);

    bool do_printout = false;

    int nEventsTotal = 0;
    int nEventsChain = ch->GetEntries();

    TFile *currentFile = 0;
    TObjArray *listOfFiles = ch->GetListOfFiles();
    TIter fileIter(listOfFiles);

    while ( (currentFile = (TFile*)fileIter.Next()) ) { 

        TFile *file = new TFile( currentFile->GetTitle() );
        TTree *tree = (TTree*)file->Get("Events");
        cms3.Init(tree);

        TString filename(currentFile->GetTitle());

        for( unsigned int event = 0; event < tree->GetEntriesFast(); ++event) {

            cms3.GetEntry(event);
            nEventsTotal++;

            // if (event > 10000) break;

            CMS3::progress(nEventsTotal, nEventsChain);

            h_met->Fill(evt_pfmet());

            for(unsigned int ijet = 0; ijet < pfjets_p4().size(); ijet++) {
                LorentzVector jet = pfjets_p4()[ijet]*pfjets_undoJEC()[ijet];
                jetp4->SetPxPyPzE(jet.Px(), jet.Py(), jet.Pz(), jet.E());
                pt = jet.Pt();
                eta = jet.Eta();
                phi = jet.Phi();
                if(pt<20) continue;


                jettype = pfjets_type()[ijet];
                if (jettype < 0) continue;


                // must have genjet with pt > 10 within dR of 0.15
                if (!(pfjets_matched()[ijet])) continue;

                is_b = jettype == 3 || jettype == 4;
                is_c = jettype == 2;
                is_udsg = jettype == 0 || jettype == 1;

                // is_b = false;
                // is_c = false;
                // is_udsg = false;
                // float mindr = 999.;
                // int absid = -1;
                // LorentzVector matchedp4;
                // for(unsigned int igen = 0;igen < genps_id().size();igen++){
                //     LorentzVector mcp4 = genps_p4()[igen];
                //     float dr = ROOT::Math::VectorUtil::DeltaR(jet,mcp4);
                //     int aid = abs(genps_id()[igen]);
                //     // don't try to match with anything other than udsgcb
                //     if (!(aid <= 5 || aid == 21)) continue;
                //     if (dr >= mindr) continue;
                //     if (dr > 0.1) continue;
                //     mindr = dr;
                //     absid = aid;
                //     matchedp4 = mcp4;
                // }
                // genp4->SetPxPyPzE(matchedp4.Px(), matchedp4.Py(), matchedp4.Pz(), matchedp4.E());
                // h_mindr->Fill(mindr);
                // h_absid->Fill(absid);
                // is_udsg = absid <= 3 || absid == 21;
                // is_c = absid == 4;
                // is_b = absid == 5;
                // // if it's not matched to anything, or if matched too many things
                // // better safe than sorry
                // if (is_udsg + is_c + is_b != 1) continue;

                csvdisc = pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag()[ijet];
                bool passes_disc = csvdisc > 0.8484;

                // int gentype = 0;
                // if (is_udsg) gentype = 0;
                // if (is_c) gentype = 1;
                // if (is_b) gentype = 2;

                if (is_b) h_genb->Fill(pt);
                if (passes_disc && is_b) h_genbtagged->Fill(pt);

                if (is_c) h_genc->Fill(pt);
                if (passes_disc && is_c) h_genctagged->Fill(pt);

                if (is_udsg) h_genudsg->Fill(pt);
                if (passes_disc && is_udsg) h_genudsgtagged->Fill(pt);

                float jete = jet.E();
                h_e->Fill(jete);
                h_pt->Fill(pt);
                h_eta->Fill(jet.Eta());
                h_pileup->Fill(pfjets_pileupJetId()[ijet]);
                h_chf->Fill(pfjets_chargedHadronE()[ijet]/jete);
                h_nhf->Fill(pfjets_neutralHadronE()[ijet]/jete);
                h_cef->Fill(pfjets_chargedEmE()[ijet]/jete);
                h_nef->Fill(pfjets_neutralEmE()[ijet]/jete);

                jetpflav = pfjets_partonFlavour()[ijet];
                jethflav = pfjets_hadronFlavour()[ijet];

                if (do_printout) {
                    std::cout << std::setprecision(3) << jettype << " " << pt << " " << eta << " " << phi << " " << jet.Et() << " " << csvdisc << " " ; // << (int)(eta/discretization) << " " << (int)(phi/discretization) << " ";
                }

                float pfe = 0.;
                int nlep = 0, ngamma = 0, ncharged = 0, nkaon = 0;
                int nbigdxy = 0;
                int nbigdz = 0;
                LorentzVector vpf = LorentzVector(0.,0.,0.,0.);
                pfcphi.clear();
                pfceta.clear();
                pfcet.clear();
                pfctype.clear();
                pfcdz.clear();
                pfcdxy.clear();
                pfcdzError.clear();
                pfcdxyError.clear();
                for(unsigned int ipf = 0;ipf < pfjets_pfcandsp4()[ijet].size();ipf++){
                    LorentzVector pfp4 = pfjets_pfcandsp4()[ijet][ipf];

                    vpf += pfp4;
                    int id = pfjets_pfcandsid()[ijet][ipf];
                    pfe += pfp4.E();

                    int pftype = 0;
                    if (idIsLep(id)) { nlep++; pftype = 0; }
                    else if (idIsGamma(id)) { ngamma++; pftype = 1; }
                    else if (idIsCharged(id)) { ncharged++; pftype = 2; }
                    else if (idIsKaon(id)) { nkaon++; pftype = 3; }
                    else {
                        pftype = 4;
                        // std::cout << "Unknown pdg id: "<< id << std::endl;
                    }


                    if (pfjets_pfcandsdxy()[ijet][ipf]>0.025) nbigdxy++;
                    if (pfjets_pfcandsdz()[ijet][ipf]>0.025) nbigdz++;

                    if (is_b)  {
                        h_dxy_b->Fill( pfjets_pfcandsdxy()[ijet][ipf] );
                        h_dz_b->Fill( pfjets_pfcandsdz()[ijet][ipf] );
                    } else {
                        h_dxy_nonb->Fill( pfjets_pfcandsdxy()[ijet][ipf] );
                        h_dz_nonb->Fill( pfjets_pfcandsdz()[ijet][ipf] );
                    }


                    pfcphi.push_back(pfp4.Phi());
                    pfceta.push_back(pfp4.Eta());
                    pfcet.push_back(pfp4.Et());
                    pfctype.push_back(pftype);
                    pfcdxy.push_back(pfjets_pfcandsdxy()[ijet][ipf]);
                    pfcdxy.push_back(pfjets_pfcandsdxyError()[ijet][ipf]);
                    pfcdzError.push_back(pfjets_pfcandsdz()[ijet][ipf]);
                    pfcdzError.push_back(pfjets_pfcandsdzError()[ijet][ipf]);


                    // int ieta = pfp4.Eta() / discretization;
                    // int iphi = pfp4.Phi() / discretization;

                    if (do_printout) {
                        // std::cout << pftype << "," << ieta << "," << iphi << "," << pfp4.Et() << " ";
                        std::cout << std::setprecision(3) << pftype << "," << pfp4.Eta() << "," << pfp4.Phi() << "," << pfp4.Et() << " ";
                    }


                }

                if (do_printout) {
                    std::cout << std::endl;
                }

                if (is_b)  {
                    h_dzbig_b->Fill(nbigdz);
                    h_dxybig_b->Fill(nbigdxy);
                } else {
                    h_dzbig_nonb->Fill(nbigdz);
                    h_dxybig_nonb->Fill(nbigdxy);
                }

                int npfc = pfjets_pfcandsp4()[ijet].size();
                h_npfcands_lep->Fill(nlep);
                h_npfcands_gamma->Fill(ngamma);
                h_npfcands_charged->Fill(ncharged);
                h_npfcands_kaon->Fill(nkaon);
                h_npfcands_other->Fill(npfc-nkaon-ncharged-ngamma-nlep);
                h_npfcands->Fill(npfc);

                h_pfcandse_jete->Fill(pfe/jete);


                t->Fill();

            } // end jet loop

        }//event loop

        delete file;
    }//file loop

    f1->Write();
    f1->Close();


    return 0;

}

