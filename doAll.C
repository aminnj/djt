{
    gSystem->Exec("mkdir -p plots");

    gROOT->ProcessLine(".L CMS3.cc+");
    gROOT->ProcessLine(".L ScanChain.C+");

    TChain *ch = new TChain("Events");
    // ch->Add("/hadoop/cms/store/user/namin/jets/ntuple_ttbar.root");
    // ch->Add("/hadoop/cms/store/user/namin/jets/ntuple_qcd.root");
    ch->Add("ntuple_ttbar.root");
    ch->Add("ntuple_qcd.root");

    ScanChain(ch, "hists_both.root");
    // ScanChain(ch, "hists_ttbar.root");

}

