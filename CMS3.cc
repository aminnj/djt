#include "CMS3.h"
CMS3 cms3;

void CMS3::Init(TTree *tree) {
  pfjets_p4_branch = 0;
  if (tree->GetAlias("pfjets_p4") != 0) {
    pfjets_p4_branch = tree->GetBranch(tree->GetAlias("pfjets_p4"));
    if (pfjets_p4_branch) { pfjets_p4_branch->SetAddress(&pfjets_p4_); }
  }
  genps_p4_branch = 0;
  if (tree->GetAlias("genps_p4") != 0) {
    genps_p4_branch = tree->GetBranch(tree->GetAlias("genps_p4"));
    if (genps_p4_branch) { genps_p4_branch->SetAddress(&genps_p4_); }
  }
  tree->SetMakeClass(1);
  evt_pfmet_JetResDown_branch = 0;
  if (tree->GetAlias("evt_pfmet_JetResDown") != 0) {
    evt_pfmet_JetResDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_JetResDown"));
    if (evt_pfmet_JetResDown_branch) { evt_pfmet_JetResDown_branch->SetAddress(&evt_pfmet_JetResDown_); }
  }
  pfjets_pfcandsdxyError_branch = 0;
  if (tree->GetAlias("pfjets_pfcandsdxyError") != 0) {
    pfjets_pfcandsdxyError_branch = tree->GetBranch(tree->GetAlias("pfjets_pfcandsdxyError"));
    if (pfjets_pfcandsdxyError_branch) { pfjets_pfcandsdxyError_branch->SetAddress(&pfjets_pfcandsdxyError_); }
  }
  evt_pfmetPhi_PhotonEnDown_branch = 0;
  if (tree->GetAlias("evt_pfmetPhi_PhotonEnDown") != 0) {
    evt_pfmetPhi_PhotonEnDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_PhotonEnDown"));
    if (evt_pfmetPhi_PhotonEnDown_branch) { evt_pfmetPhi_PhotonEnDown_branch->SetAddress(&evt_pfmetPhi_PhotonEnDown_); }
  }
  pfjets_pfcandsid_branch = 0;
  if (tree->GetAlias("pfjets_pfcandsid") != 0) {
    pfjets_pfcandsid_branch = tree->GetBranch(tree->GetAlias("pfjets_pfcandsid"));
    if (pfjets_pfcandsid_branch) { pfjets_pfcandsid_branch->SetAddress(&pfjets_pfcandsid_); }
  }
  pfjets_partonFlavour_branch = 0;
  if (tree->GetAlias("pfjets_partonFlavour") != 0) {
    pfjets_partonFlavour_branch = tree->GetBranch(tree->GetAlias("pfjets_partonFlavour"));
    if (pfjets_partonFlavour_branch) { pfjets_partonFlavour_branch->SetAddress(&pfjets_partonFlavour_); }
  }
  evt_calomet_branch = 0;
  if (tree->GetAlias("evt_calomet") != 0) {
    evt_calomet_branch = tree->GetBranch(tree->GetAlias("evt_calomet"));
    if (evt_calomet_branch) { evt_calomet_branch->SetAddress(&evt_calomet_); }
  }
  genps_id_mother_branch = 0;
  if (tree->GetAlias("genps_id_mother") != 0) {
    genps_id_mother_branch = tree->GetBranch(tree->GetAlias("genps_id_mother"));
    if (genps_id_mother_branch) { genps_id_mother_branch->SetAddress(&genps_id_mother_); }
  }
  evt_pfmet_JetResUp_branch = 0;
  if (tree->GetAlias("evt_pfmet_JetResUp") != 0) {
    evt_pfmet_JetResUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_JetResUp"));
    if (evt_pfmet_JetResUp_branch) { evt_pfmet_JetResUp_branch->SetAddress(&evt_pfmet_JetResUp_); }
  }
  genps_status_branch = 0;
  if (tree->GetAlias("genps_status") != 0) {
    genps_status_branch = tree->GetBranch(tree->GetAlias("genps_status"));
    if (genps_status_branch) { genps_status_branch->SetAddress(&genps_status_); }
  }
  genps_id_branch = 0;
  if (tree->GetAlias("genps_id") != 0) {
    genps_id_branch = tree->GetBranch(tree->GetAlias("genps_id"));
    if (genps_id_branch) { genps_id_branch->SetAddress(&genps_id_); }
  }
  evt_pfmet_TauEnDown_branch = 0;
  if (tree->GetAlias("evt_pfmet_TauEnDown") != 0) {
    evt_pfmet_TauEnDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_TauEnDown"));
    if (evt_pfmet_TauEnDown_branch) { evt_pfmet_TauEnDown_branch->SetAddress(&evt_pfmet_TauEnDown_); }
  }
  pfjets_chargedEmE_branch = 0;
  if (tree->GetAlias("pfjets_chargedEmE") != 0) {
    pfjets_chargedEmE_branch = tree->GetBranch(tree->GetAlias("pfjets_chargedEmE"));
    if (pfjets_chargedEmE_branch) { pfjets_chargedEmE_branch->SetAddress(&pfjets_chargedEmE_); }
  }
  evt_pfmet_raw_branch = 0;
  if (tree->GetAlias("evt_pfmet_raw") != 0) {
    evt_pfmet_raw_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_raw"));
    if (evt_pfmet_raw_branch) { evt_pfmet_raw_branch->SetAddress(&evt_pfmet_raw_); }
  }
  pfjets_chargedHadronE_branch = 0;
  if (tree->GetAlias("pfjets_chargedHadronE") != 0) {
    pfjets_chargedHadronE_branch = tree->GetBranch(tree->GetAlias("pfjets_chargedHadronE"));
    if (pfjets_chargedHadronE_branch) { pfjets_chargedHadronE_branch->SetAddress(&pfjets_chargedHadronE_); }
  }
  evt_detectorStatus_branch = 0;
  if (tree->GetAlias("evt_detectorStatus") != 0) {
    evt_detectorStatus_branch = tree->GetBranch(tree->GetAlias("evt_detectorStatus"));
    if (evt_detectorStatus_branch) { evt_detectorStatus_branch->SetAddress(&evt_detectorStatus_); }
  }
  evt_pfmet_MuonEnUp_branch = 0;
  if (tree->GetAlias("evt_pfmet_MuonEnUp") != 0) {
    evt_pfmet_MuonEnUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_MuonEnUp"));
    if (evt_pfmet_MuonEnUp_branch) { evt_pfmet_MuonEnUp_branch->SetAddress(&evt_pfmet_MuonEnUp_); }
  }
  gen_metPhi_branch = 0;
  if (tree->GetAlias("gen_metPhi") != 0) {
    gen_metPhi_branch = tree->GetBranch(tree->GetAlias("gen_metPhi"));
    if (gen_metPhi_branch) { gen_metPhi_branch->SetAddress(&gen_metPhi_); }
  }
  evt_calometPhi_branch = 0;
  if (tree->GetAlias("evt_calometPhi") != 0) {
    evt_calometPhi_branch = tree->GetBranch(tree->GetAlias("evt_calometPhi"));
    if (evt_calometPhi_branch) { evt_calometPhi_branch->SetAddress(&evt_calometPhi_); }
  }
  evt_instantLumi_branch = 0;
  if (tree->GetAlias("evt_instantLumi") != 0) {
    evt_instantLumi_branch = tree->GetBranch(tree->GetAlias("evt_instantLumi"));
    if (evt_instantLumi_branch) { evt_instantLumi_branch->SetAddress(&evt_instantLumi_); }
  }
  pfjets_pfcandsp4_branch = 0;
  if (tree->GetAlias("pfjets_pfcandsp4") != 0) {
    pfjets_pfcandsp4_branch = tree->GetBranch(tree->GetAlias("pfjets_pfcandsp4"));
    if (pfjets_pfcandsp4_branch) { pfjets_pfcandsp4_branch->SetAddress(&pfjets_pfcandsp4_); }
  }
  evt_pfsumet_branch = 0;
  if (tree->GetAlias("evt_pfsumet") != 0) {
    evt_pfsumet_branch = tree->GetBranch(tree->GetAlias("evt_pfsumet"));
    if (evt_pfsumet_branch) { evt_pfsumet_branch->SetAddress(&evt_pfsumet_); }
  }
  pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag_branch = 0;
  if (tree->GetAlias("pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag") != 0) {
    pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag_branch = tree->GetBranch(tree->GetAlias("pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag"));
    if (pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag_branch) { pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag_branch->SetAddress(&pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag_); }
  }
  evt_bunchCrossing_branch = 0;
  if (tree->GetAlias("evt_bunchCrossing") != 0) {
    evt_bunchCrossing_branch = tree->GetBranch(tree->GetAlias("evt_bunchCrossing"));
    if (evt_bunchCrossing_branch) { evt_bunchCrossing_branch->SetAddress(&evt_bunchCrossing_); }
  }
  evt_pfmetPhi_branch = 0;
  if (tree->GetAlias("evt_pfmetPhi") != 0) {
    evt_pfmetPhi_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi"));
    if (evt_pfmetPhi_branch) { evt_pfmetPhi_branch->SetAddress(&evt_pfmetPhi_); }
  }
  evt_pfsumet_raw_branch = 0;
  if (tree->GetAlias("evt_pfsumet_raw") != 0) {
    evt_pfsumet_raw_branch = tree->GetBranch(tree->GetAlias("evt_pfsumet_raw"));
    if (evt_pfsumet_raw_branch) { evt_pfsumet_raw_branch->SetAddress(&evt_pfsumet_raw_); }
  }
  evt_pfmetPhi_raw_branch = 0;
  if (tree->GetAlias("evt_pfmetPhi_raw") != 0) {
    evt_pfmetPhi_raw_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_raw"));
    if (evt_pfmetPhi_raw_branch) { evt_pfmetPhi_raw_branch->SetAddress(&evt_pfmetPhi_raw_); }
  }
  evt_pfmetPhi_JetResUp_branch = 0;
  if (tree->GetAlias("evt_pfmetPhi_JetResUp") != 0) {
    evt_pfmetPhi_JetResUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_JetResUp"));
    if (evt_pfmetPhi_JetResUp_branch) { evt_pfmetPhi_JetResUp_branch->SetAddress(&evt_pfmetPhi_JetResUp_); }
  }
  pfjets_pfcandsdzError_branch = 0;
  if (tree->GetAlias("pfjets_pfcandsdzError") != 0) {
    pfjets_pfcandsdzError_branch = tree->GetBranch(tree->GetAlias("pfjets_pfcandsdzError"));
    if (pfjets_pfcandsdzError_branch) { pfjets_pfcandsdzError_branch->SetAddress(&pfjets_pfcandsdzError_); }
  }
  evt_bField_branch = 0;
  if (tree->GetAlias("evt_bField") != 0) {
    evt_bField_branch = tree->GetBranch(tree->GetAlias("evt_bField"));
    if (evt_bField_branch) { evt_bField_branch->SetAddress(&evt_bField_); }
  }
  evt_timestamp_branch = 0;
  if (tree->GetAlias("evt_timestamp") != 0) {
    evt_timestamp_branch = tree->GetBranch(tree->GetAlias("evt_timestamp"));
    if (evt_timestamp_branch) { evt_timestamp_branch->SetAddress(&evt_timestamp_); }
  }
  pfjets_pileupJetId_branch = 0;
  if (tree->GetAlias("pfjets_pileupJetId") != 0) {
    pfjets_pileupJetId_branch = tree->GetBranch(tree->GetAlias("pfjets_pileupJetId"));
    if (pfjets_pileupJetId_branch) { pfjets_pileupJetId_branch->SetAddress(&pfjets_pileupJetId_); }
  }
  evt_storeNumber_branch = 0;
  if (tree->GetAlias("evt_storeNumber") != 0) {
    evt_storeNumber_branch = tree->GetBranch(tree->GetAlias("evt_storeNumber"));
    if (evt_storeNumber_branch) { evt_storeNumber_branch->SetAddress(&evt_storeNumber_); }
  }
  pfjets_undoJEC_branch = 0;
  if (tree->GetAlias("pfjets_undoJEC") != 0) {
    pfjets_undoJEC_branch = tree->GetBranch(tree->GetAlias("pfjets_undoJEC"));
    if (pfjets_undoJEC_branch) { pfjets_undoJEC_branch->SetAddress(&pfjets_undoJEC_); }
  }
  evt_lumiRun_branch = 0;
  if (tree->GetAlias("evt_lumiRun") != 0) {
    evt_lumiRun_branch = tree->GetBranch(tree->GetAlias("evt_lumiRun"));
    if (evt_lumiRun_branch) { evt_lumiRun_branch->SetAddress(&evt_lumiRun_); }
  }
  evt_pfmetPhi_JetResDown_branch = 0;
  if (tree->GetAlias("evt_pfmetPhi_JetResDown") != 0) {
    evt_pfmetPhi_JetResDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_JetResDown"));
    if (evt_pfmetPhi_JetResDown_branch) { evt_pfmetPhi_JetResDown_branch->SetAddress(&evt_pfmetPhi_JetResDown_); }
  }
  evt_lumiFill_branch = 0;
  if (tree->GetAlias("evt_lumiFill") != 0) {
    evt_lumiFill_branch = tree->GetBranch(tree->GetAlias("evt_lumiFill"));
    if (evt_lumiFill_branch) { evt_lumiFill_branch->SetAddress(&evt_lumiFill_); }
  }
  pfjets_neutralEmE_branch = 0;
  if (tree->GetAlias("pfjets_neutralEmE") != 0) {
    pfjets_neutralEmE_branch = tree->GetBranch(tree->GetAlias("pfjets_neutralEmE"));
    if (pfjets_neutralEmE_branch) { pfjets_neutralEmE_branch->SetAddress(&pfjets_neutralEmE_); }
  }
  evt_run_branch = 0;
  if (tree->GetAlias("evt_run") != 0) {
    evt_run_branch = tree->GetBranch(tree->GetAlias("evt_run"));
    if (evt_run_branch) { evt_run_branch->SetAddress(&evt_run_); }
  }
  evt_pfmetPhi_MuonEnDown_branch = 0;
  if (tree->GetAlias("evt_pfmetPhi_MuonEnDown") != 0) {
    evt_pfmetPhi_MuonEnDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_MuonEnDown"));
    if (evt_pfmetPhi_MuonEnDown_branch) { evt_pfmetPhi_MuonEnDown_branch->SetAddress(&evt_pfmetPhi_MuonEnDown_); }
  }
  evt_orbitNumber_branch = 0;
  if (tree->GetAlias("evt_orbitNumber") != 0) {
    evt_orbitNumber_branch = tree->GetBranch(tree->GetAlias("evt_orbitNumber"));
    if (evt_orbitNumber_branch) { evt_orbitNumber_branch->SetAddress(&evt_orbitNumber_); }
  }
  evt_pfmetPhi_ElectronEnDown_branch = 0;
  if (tree->GetAlias("evt_pfmetPhi_ElectronEnDown") != 0) {
    evt_pfmetPhi_ElectronEnDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_ElectronEnDown"));
    if (evt_pfmetPhi_ElectronEnDown_branch) { evt_pfmetPhi_ElectronEnDown_branch->SetAddress(&evt_pfmetPhi_ElectronEnDown_); }
  }
  evt_experimentType_branch = 0;
  if (tree->GetAlias("evt_experimentType") != 0) {
    evt_experimentType_branch = tree->GetBranch(tree->GetAlias("evt_experimentType"));
    if (evt_experimentType_branch) { evt_experimentType_branch->SetAddress(&evt_experimentType_); }
  }
  evt_pfmet_MuonEnDown_branch = 0;
  if (tree->GetAlias("evt_pfmet_MuonEnDown") != 0) {
    evt_pfmet_MuonEnDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_MuonEnDown"));
    if (evt_pfmet_MuonEnDown_branch) { evt_pfmet_MuonEnDown_branch->SetAddress(&evt_pfmet_MuonEnDown_); }
  }
  evt_pfmetPhi_UnclusteredEnDown_branch = 0;
  if (tree->GetAlias("evt_pfmetPhi_UnclusteredEnDown") != 0) {
    evt_pfmetPhi_UnclusteredEnDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_UnclusteredEnDown"));
    if (evt_pfmetPhi_UnclusteredEnDown_branch) { evt_pfmetPhi_UnclusteredEnDown_branch->SetAddress(&evt_pfmetPhi_UnclusteredEnDown_); }
  }
  evt_pfmetPhi_UnclusteredEnUp_branch = 0;
  if (tree->GetAlias("evt_pfmetPhi_UnclusteredEnUp") != 0) {
    evt_pfmetPhi_UnclusteredEnUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_UnclusteredEnUp"));
    if (evt_pfmetPhi_UnclusteredEnUp_branch) { evt_pfmetPhi_UnclusteredEnUp_branch->SetAddress(&evt_pfmetPhi_UnclusteredEnUp_); }
  }
  evt_pfmet_PhotonEnUp_branch = 0;
  if (tree->GetAlias("evt_pfmet_PhotonEnUp") != 0) {
    evt_pfmet_PhotonEnUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_PhotonEnUp"));
    if (evt_pfmet_PhotonEnUp_branch) { evt_pfmet_PhotonEnUp_branch->SetAddress(&evt_pfmet_PhotonEnUp_); }
  }
  evt_pileupRMS_branch = 0;
  if (tree->GetAlias("evt_pileupRMS") != 0) {
    evt_pileupRMS_branch = tree->GetBranch(tree->GetAlias("evt_pileupRMS"));
    if (evt_pileupRMS_branch) { evt_pileupRMS_branch->SetAddress(&evt_pileupRMS_); }
  }
  evt_pfmetPhi_MuonEnUp_branch = 0;
  if (tree->GetAlias("evt_pfmetPhi_MuonEnUp") != 0) {
    evt_pfmetPhi_MuonEnUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_MuonEnUp"));
    if (evt_pfmetPhi_MuonEnUp_branch) { evt_pfmetPhi_MuonEnUp_branch->SetAddress(&evt_pfmetPhi_MuonEnUp_); }
  }
  evt_pfmetPhi_JetEnDown_branch = 0;
  if (tree->GetAlias("evt_pfmetPhi_JetEnDown") != 0) {
    evt_pfmetPhi_JetEnDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_JetEnDown"));
    if (evt_pfmetPhi_JetEnDown_branch) { evt_pfmetPhi_JetEnDown_branch->SetAddress(&evt_pfmetPhi_JetEnDown_); }
  }
  evt_pfmet_ElectronEnDown_branch = 0;
  if (tree->GetAlias("evt_pfmet_ElectronEnDown") != 0) {
    evt_pfmet_ElectronEnDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_ElectronEnDown"));
    if (evt_pfmet_ElectronEnDown_branch) { evt_pfmet_ElectronEnDown_branch->SetAddress(&evt_pfmet_ElectronEnDown_); }
  }
  pfjets_neutralHadronE_branch = 0;
  if (tree->GetAlias("pfjets_neutralHadronE") != 0) {
    pfjets_neutralHadronE_branch = tree->GetBranch(tree->GetAlias("pfjets_neutralHadronE"));
    if (pfjets_neutralHadronE_branch) { pfjets_neutralHadronE_branch->SetAddress(&pfjets_neutralHadronE_); }
  }
  pfjets_pfcandsdz_branch = 0;
  if (tree->GetAlias("pfjets_pfcandsdz") != 0) {
    pfjets_pfcandsdz_branch = tree->GetBranch(tree->GetAlias("pfjets_pfcandsdz"));
    if (pfjets_pfcandsdz_branch) { pfjets_pfcandsdz_branch->SetAddress(&pfjets_pfcandsdz_); }
  }
  pfjets_pfcandshighPurity_branch = 0;
  if (tree->GetAlias("pfjets_pfcandshighPurity") != 0) {
    pfjets_pfcandshighPurity_branch = tree->GetBranch(tree->GetAlias("pfjets_pfcandshighPurity"));
    if (pfjets_pfcandshighPurity_branch) { pfjets_pfcandshighPurity_branch->SetAddress(&pfjets_pfcandshighPurity_); }
  }
  evt_dataset_branch = 0;
  if (tree->GetAlias("evt_dataset") != 0) {
    evt_dataset_branch = tree->GetBranch(tree->GetAlias("evt_dataset"));
    if (evt_dataset_branch) { evt_dataset_branch->SetAddress(&evt_dataset_); }
  }
  pfjets_pfcandsdxy_branch = 0;
  if (tree->GetAlias("pfjets_pfcandsdxy") != 0) {
    pfjets_pfcandsdxy_branch = tree->GetBranch(tree->GetAlias("pfjets_pfcandsdxy"));
    if (pfjets_pfcandsdxy_branch) { pfjets_pfcandsdxy_branch->SetAddress(&pfjets_pfcandsdxy_); }
  }
  evt_pfmet_UnclusteredEnDown_branch = 0;
  if (tree->GetAlias("evt_pfmet_UnclusteredEnDown") != 0) {
    evt_pfmet_UnclusteredEnDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_UnclusteredEnDown"));
    if (evt_pfmet_UnclusteredEnDown_branch) { evt_pfmet_UnclusteredEnDown_branch->SetAddress(&evt_pfmet_UnclusteredEnDown_); }
  }
  evt_pfmetPhi_TauEnUp_branch = 0;
  if (tree->GetAlias("evt_pfmetPhi_TauEnUp") != 0) {
    evt_pfmetPhi_TauEnUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_TauEnUp"));
    if (evt_pfmetPhi_TauEnUp_branch) { evt_pfmetPhi_TauEnUp_branch->SetAddress(&evt_pfmetPhi_TauEnUp_); }
  }
  evt_pfmet_JetEnUp_branch = 0;
  if (tree->GetAlias("evt_pfmet_JetEnUp") != 0) {
    evt_pfmet_JetEnUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_JetEnUp"));
    if (evt_pfmet_JetEnUp_branch) { evt_pfmet_JetEnUp_branch->SetAddress(&evt_pfmet_JetEnUp_); }
  }
  gen_met_branch = 0;
  if (tree->GetAlias("gen_met") != 0) {
    gen_met_branch = tree->GetBranch(tree->GetAlias("gen_met"));
    if (gen_met_branch) { gen_met_branch->SetAddress(&gen_met_); }
  }
  evt_instantLumiErr_branch = 0;
  if (tree->GetAlias("evt_instantLumiErr") != 0) {
    evt_instantLumiErr_branch = tree->GetBranch(tree->GetAlias("evt_instantLumiErr"));
    if (evt_instantLumiErr_branch) { evt_instantLumiErr_branch->SetAddress(&evt_instantLumiErr_); }
  }
  evt_pfmetSig_branch = 0;
  if (tree->GetAlias("evt_pfmetSig") != 0) {
    evt_pfmetSig_branch = tree->GetBranch(tree->GetAlias("evt_pfmetSig"));
    if (evt_pfmetSig_branch) { evt_pfmetSig_branch->SetAddress(&evt_pfmetSig_); }
  }
  evt_pfmetSignificance_branch = 0;
  if (tree->GetAlias("evt_pfmetSignificance") != 0) {
    evt_pfmetSignificance_branch = tree->GetBranch(tree->GetAlias("evt_pfmetSignificance"));
    if (evt_pfmetSignificance_branch) { evt_pfmetSignificance_branch->SetAddress(&evt_pfmetSignificance_); }
  }
  pfjets_muonE_branch = 0;
  if (tree->GetAlias("pfjets_muonE") != 0) {
    pfjets_muonE_branch = tree->GetBranch(tree->GetAlias("pfjets_muonE"));
    if (pfjets_muonE_branch) { pfjets_muonE_branch->SetAddress(&pfjets_muonE_); }
  }
  pfjets_photonE_branch = 0;
  if (tree->GetAlias("pfjets_photonE") != 0) {
    pfjets_photonE_branch = tree->GetBranch(tree->GetAlias("pfjets_photonE"));
    if (pfjets_photonE_branch) { pfjets_photonE_branch->SetAddress(&pfjets_photonE_); }
  }
  evt_lumiBlock_branch = 0;
  if (tree->GetAlias("evt_lumiBlock") != 0) {
    evt_lumiBlock_branch = tree->GetBranch(tree->GetAlias("evt_lumiBlock"));
    if (evt_lumiBlock_branch) { evt_lumiBlock_branch->SetAddress(&evt_lumiBlock_); }
  }
  evt_pileup_branch = 0;
  if (tree->GetAlias("evt_pileup") != 0) {
    evt_pileup_branch = tree->GetBranch(tree->GetAlias("evt_pileup"));
    if (evt_pileup_branch) { evt_pileup_branch->SetAddress(&evt_pileup_); }
  }
  pfjets_electronE_branch = 0;
  if (tree->GetAlias("pfjets_electronE") != 0) {
    pfjets_electronE_branch = tree->GetBranch(tree->GetAlias("pfjets_electronE"));
    if (pfjets_electronE_branch) { pfjets_electronE_branch->SetAddress(&pfjets_electronE_); }
  }
  evt_pfmet_PhotonEnDown_branch = 0;
  if (tree->GetAlias("evt_pfmet_PhotonEnDown") != 0) {
    evt_pfmet_PhotonEnDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_PhotonEnDown"));
    if (evt_pfmet_PhotonEnDown_branch) { evt_pfmet_PhotonEnDown_branch->SetAddress(&evt_pfmet_PhotonEnDown_); }
  }
  pfjets_area_branch = 0;
  if (tree->GetAlias("pfjets_area") != 0) {
    pfjets_area_branch = tree->GetBranch(tree->GetAlias("pfjets_area"));
    if (pfjets_area_branch) { pfjets_area_branch->SetAddress(&pfjets_area_); }
  }
  evt_pfmet_JetEnDown_branch = 0;
  if (tree->GetAlias("evt_pfmet_JetEnDown") != 0) {
    evt_pfmet_JetEnDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_JetEnDown"));
    if (evt_pfmet_JetEnDown_branch) { evt_pfmet_JetEnDown_branch->SetAddress(&evt_pfmet_JetEnDown_); }
  }
  evt_pfmetPhi_TauEnDown_branch = 0;
  if (tree->GetAlias("evt_pfmetPhi_TauEnDown") != 0) {
    evt_pfmetPhi_TauEnDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_TauEnDown"));
    if (evt_pfmetPhi_TauEnDown_branch) { evt_pfmetPhi_TauEnDown_branch->SetAddress(&evt_pfmetPhi_TauEnDown_); }
  }
  evt_pfmet_UnclusteredEnUp_branch = 0;
  if (tree->GetAlias("evt_pfmet_UnclusteredEnUp") != 0) {
    evt_pfmet_UnclusteredEnUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_UnclusteredEnUp"));
    if (evt_pfmet_UnclusteredEnUp_branch) { evt_pfmet_UnclusteredEnUp_branch->SetAddress(&evt_pfmet_UnclusteredEnUp_); }
  }
  evt_pfmet_TauEnUp_branch = 0;
  if (tree->GetAlias("evt_pfmet_TauEnUp") != 0) {
    evt_pfmet_TauEnUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_TauEnUp"));
    if (evt_pfmet_TauEnUp_branch) { evt_pfmet_TauEnUp_branch->SetAddress(&evt_pfmet_TauEnUp_); }
  }
  evt_pfmetPhi_PhotonEnUp_branch = 0;
  if (tree->GetAlias("evt_pfmetPhi_PhotonEnUp") != 0) {
    evt_pfmetPhi_PhotonEnUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_PhotonEnUp"));
    if (evt_pfmetPhi_PhotonEnUp_branch) { evt_pfmetPhi_PhotonEnUp_branch->SetAddress(&evt_pfmetPhi_PhotonEnUp_); }
  }
  evt_event_branch = 0;
  if (tree->GetAlias("evt_event") != 0) {
    evt_event_branch = tree->GetBranch(tree->GetAlias("evt_event"));
    if (evt_event_branch) { evt_event_branch->SetAddress(&evt_event_); }
  }
  evt_pfmetPhi_JetEnUp_branch = 0;
  if (tree->GetAlias("evt_pfmetPhi_JetEnUp") != 0) {
    evt_pfmetPhi_JetEnUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_JetEnUp"));
    if (evt_pfmetPhi_JetEnUp_branch) { evt_pfmetPhi_JetEnUp_branch->SetAddress(&evt_pfmetPhi_JetEnUp_); }
  }
  pfjets_hadronFlavour_branch = 0;
  if (tree->GetAlias("pfjets_hadronFlavour") != 0) {
    pfjets_hadronFlavour_branch = tree->GetBranch(tree->GetAlias("pfjets_hadronFlavour"));
    if (pfjets_hadronFlavour_branch) { pfjets_hadronFlavour_branch->SetAddress(&pfjets_hadronFlavour_); }
  }
  evt_pfmet_ElectronEnUp_branch = 0;
  if (tree->GetAlias("evt_pfmet_ElectronEnUp") != 0) {
    evt_pfmet_ElectronEnUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_ElectronEnUp"));
    if (evt_pfmet_ElectronEnUp_branch) { evt_pfmet_ElectronEnUp_branch->SetAddress(&evt_pfmet_ElectronEnUp_); }
  }
  evt_CMS3tag_branch = 0;
  if (tree->GetAlias("evt_CMS3tag") != 0) {
    evt_CMS3tag_branch = tree->GetBranch(tree->GetAlias("evt_CMS3tag"));
    if (evt_CMS3tag_branch) { evt_CMS3tag_branch->SetAddress(&evt_CMS3tag_); }
  }
  evt_isRealData_branch = 0;
  if (tree->GetAlias("evt_isRealData") != 0) {
    evt_isRealData_branch = tree->GetBranch(tree->GetAlias("evt_isRealData"));
    if (evt_isRealData_branch) { evt_isRealData_branch->SetAddress(&evt_isRealData_); }
  }
  evt_pfmet_branch = 0;
  if (tree->GetAlias("evt_pfmet") != 0) {
    evt_pfmet_branch = tree->GetBranch(tree->GetAlias("evt_pfmet"));
    if (evt_pfmet_branch) { evt_pfmet_branch->SetAddress(&evt_pfmet_); }
  }
  evt_pfmetPhi_ElectronEnUp_branch = 0;
  if (tree->GetAlias("evt_pfmetPhi_ElectronEnUp") != 0) {
    evt_pfmetPhi_ElectronEnUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_ElectronEnUp"));
    if (evt_pfmetPhi_ElectronEnUp_branch) { evt_pfmetPhi_ElectronEnUp_branch->SetAddress(&evt_pfmetPhi_ElectronEnUp_); }
  }
  tree->SetMakeClass(0);
}
void CMS3::GetEntry(unsigned int idx) {
  index = idx;
  evt_pfmet_JetResDown_isLoaded = false;
  pfjets_pfcandsdxyError_isLoaded = false;
  evt_pfmetPhi_PhotonEnDown_isLoaded = false;
  pfjets_pfcandsid_isLoaded = false;
  pfjets_partonFlavour_isLoaded = false;
  evt_calomet_isLoaded = false;
  genps_id_mother_isLoaded = false;
  evt_pfmet_JetResUp_isLoaded = false;
  genps_status_isLoaded = false;
  genps_id_isLoaded = false;
  evt_pfmet_TauEnDown_isLoaded = false;
  pfjets_chargedEmE_isLoaded = false;
  evt_pfmet_raw_isLoaded = false;
  pfjets_chargedHadronE_isLoaded = false;
  evt_detectorStatus_isLoaded = false;
  evt_pfmet_MuonEnUp_isLoaded = false;
  gen_metPhi_isLoaded = false;
  evt_calometPhi_isLoaded = false;
  evt_instantLumi_isLoaded = false;
  pfjets_pfcandsp4_isLoaded = false;
  pfjets_p4_isLoaded = false;
  evt_pfsumet_isLoaded = false;
  pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag_isLoaded = false;
  evt_bunchCrossing_isLoaded = false;
  evt_pfmetPhi_isLoaded = false;
  evt_pfsumet_raw_isLoaded = false;
  evt_pfmetPhi_raw_isLoaded = false;
  evt_pfmetPhi_JetResUp_isLoaded = false;
  pfjets_pfcandsdzError_isLoaded = false;
  evt_bField_isLoaded = false;
  evt_timestamp_isLoaded = false;
  pfjets_pileupJetId_isLoaded = false;
  evt_storeNumber_isLoaded = false;
  pfjets_undoJEC_isLoaded = false;
  genps_p4_isLoaded = false;
  evt_lumiRun_isLoaded = false;
  evt_pfmetPhi_JetResDown_isLoaded = false;
  evt_lumiFill_isLoaded = false;
  pfjets_neutralEmE_isLoaded = false;
  evt_run_isLoaded = false;
  evt_pfmetPhi_MuonEnDown_isLoaded = false;
  evt_orbitNumber_isLoaded = false;
  evt_pfmetPhi_ElectronEnDown_isLoaded = false;
  evt_experimentType_isLoaded = false;
  evt_pfmet_MuonEnDown_isLoaded = false;
  evt_pfmetPhi_UnclusteredEnDown_isLoaded = false;
  evt_pfmetPhi_UnclusteredEnUp_isLoaded = false;
  evt_pfmet_PhotonEnUp_isLoaded = false;
  evt_pileupRMS_isLoaded = false;
  evt_pfmetPhi_MuonEnUp_isLoaded = false;
  evt_pfmetPhi_JetEnDown_isLoaded = false;
  evt_pfmet_ElectronEnDown_isLoaded = false;
  pfjets_neutralHadronE_isLoaded = false;
  pfjets_pfcandsdz_isLoaded = false;
  pfjets_pfcandshighPurity_isLoaded = false;
  evt_dataset_isLoaded = false;
  pfjets_pfcandsdxy_isLoaded = false;
  evt_pfmet_UnclusteredEnDown_isLoaded = false;
  evt_pfmetPhi_TauEnUp_isLoaded = false;
  evt_pfmet_JetEnUp_isLoaded = false;
  gen_met_isLoaded = false;
  evt_instantLumiErr_isLoaded = false;
  evt_pfmetSig_isLoaded = false;
  evt_pfmetSignificance_isLoaded = false;
  pfjets_muonE_isLoaded = false;
  pfjets_photonE_isLoaded = false;
  evt_lumiBlock_isLoaded = false;
  evt_pileup_isLoaded = false;
  pfjets_electronE_isLoaded = false;
  evt_pfmet_PhotonEnDown_isLoaded = false;
  pfjets_area_isLoaded = false;
  evt_pfmet_JetEnDown_isLoaded = false;
  evt_pfmetPhi_TauEnDown_isLoaded = false;
  evt_pfmet_UnclusteredEnUp_isLoaded = false;
  evt_pfmet_TauEnUp_isLoaded = false;
  evt_pfmetPhi_PhotonEnUp_isLoaded = false;
  evt_event_isLoaded = false;
  evt_pfmetPhi_JetEnUp_isLoaded = false;
  pfjets_hadronFlavour_isLoaded = false;
  evt_pfmet_ElectronEnUp_isLoaded = false;
  evt_CMS3tag_isLoaded = false;
  evt_isRealData_isLoaded = false;
  evt_pfmet_isLoaded = false;
  evt_pfmetPhi_ElectronEnUp_isLoaded = false;
}
void CMS3::LoadAllBranches() {
  if (evt_pfmet_JetResDown_branch != 0) evt_pfmet_JetResDown();
  if (pfjets_pfcandsdxyError_branch != 0) pfjets_pfcandsdxyError();
  if (evt_pfmetPhi_PhotonEnDown_branch != 0) evt_pfmetPhi_PhotonEnDown();
  if (pfjets_pfcandsid_branch != 0) pfjets_pfcandsid();
  if (pfjets_partonFlavour_branch != 0) pfjets_partonFlavour();
  if (evt_calomet_branch != 0) evt_calomet();
  if (genps_id_mother_branch != 0) genps_id_mother();
  if (evt_pfmet_JetResUp_branch != 0) evt_pfmet_JetResUp();
  if (genps_status_branch != 0) genps_status();
  if (genps_id_branch != 0) genps_id();
  if (evt_pfmet_TauEnDown_branch != 0) evt_pfmet_TauEnDown();
  if (pfjets_chargedEmE_branch != 0) pfjets_chargedEmE();
  if (evt_pfmet_raw_branch != 0) evt_pfmet_raw();
  if (pfjets_chargedHadronE_branch != 0) pfjets_chargedHadronE();
  if (evt_detectorStatus_branch != 0) evt_detectorStatus();
  if (evt_pfmet_MuonEnUp_branch != 0) evt_pfmet_MuonEnUp();
  if (gen_metPhi_branch != 0) gen_metPhi();
  if (evt_calometPhi_branch != 0) evt_calometPhi();
  if (evt_instantLumi_branch != 0) evt_instantLumi();
  if (pfjets_pfcandsp4_branch != 0) pfjets_pfcandsp4();
  if (pfjets_p4_branch != 0) pfjets_p4();
  if (evt_pfsumet_branch != 0) evt_pfsumet();
  if (pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag_branch != 0) pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag();
  if (evt_bunchCrossing_branch != 0) evt_bunchCrossing();
  if (evt_pfmetPhi_branch != 0) evt_pfmetPhi();
  if (evt_pfsumet_raw_branch != 0) evt_pfsumet_raw();
  if (evt_pfmetPhi_raw_branch != 0) evt_pfmetPhi_raw();
  if (evt_pfmetPhi_JetResUp_branch != 0) evt_pfmetPhi_JetResUp();
  if (pfjets_pfcandsdzError_branch != 0) pfjets_pfcandsdzError();
  if (evt_bField_branch != 0) evt_bField();
  if (evt_timestamp_branch != 0) evt_timestamp();
  if (pfjets_pileupJetId_branch != 0) pfjets_pileupJetId();
  if (evt_storeNumber_branch != 0) evt_storeNumber();
  if (pfjets_undoJEC_branch != 0) pfjets_undoJEC();
  if (genps_p4_branch != 0) genps_p4();
  if (evt_lumiRun_branch != 0) evt_lumiRun();
  if (evt_pfmetPhi_JetResDown_branch != 0) evt_pfmetPhi_JetResDown();
  if (evt_lumiFill_branch != 0) evt_lumiFill();
  if (pfjets_neutralEmE_branch != 0) pfjets_neutralEmE();
  if (evt_run_branch != 0) evt_run();
  if (evt_pfmetPhi_MuonEnDown_branch != 0) evt_pfmetPhi_MuonEnDown();
  if (evt_orbitNumber_branch != 0) evt_orbitNumber();
  if (evt_pfmetPhi_ElectronEnDown_branch != 0) evt_pfmetPhi_ElectronEnDown();
  if (evt_experimentType_branch != 0) evt_experimentType();
  if (evt_pfmet_MuonEnDown_branch != 0) evt_pfmet_MuonEnDown();
  if (evt_pfmetPhi_UnclusteredEnDown_branch != 0) evt_pfmetPhi_UnclusteredEnDown();
  if (evt_pfmetPhi_UnclusteredEnUp_branch != 0) evt_pfmetPhi_UnclusteredEnUp();
  if (evt_pfmet_PhotonEnUp_branch != 0) evt_pfmet_PhotonEnUp();
  if (evt_pileupRMS_branch != 0) evt_pileupRMS();
  if (evt_pfmetPhi_MuonEnUp_branch != 0) evt_pfmetPhi_MuonEnUp();
  if (evt_pfmetPhi_JetEnDown_branch != 0) evt_pfmetPhi_JetEnDown();
  if (evt_pfmet_ElectronEnDown_branch != 0) evt_pfmet_ElectronEnDown();
  if (pfjets_neutralHadronE_branch != 0) pfjets_neutralHadronE();
  if (pfjets_pfcandsdz_branch != 0) pfjets_pfcandsdz();
  if (pfjets_pfcandshighPurity_branch != 0) pfjets_pfcandshighPurity();
  if (evt_dataset_branch != 0) evt_dataset();
  if (pfjets_pfcandsdxy_branch != 0) pfjets_pfcandsdxy();
  if (evt_pfmet_UnclusteredEnDown_branch != 0) evt_pfmet_UnclusteredEnDown();
  if (evt_pfmetPhi_TauEnUp_branch != 0) evt_pfmetPhi_TauEnUp();
  if (evt_pfmet_JetEnUp_branch != 0) evt_pfmet_JetEnUp();
  if (gen_met_branch != 0) gen_met();
  if (evt_instantLumiErr_branch != 0) evt_instantLumiErr();
  if (evt_pfmetSig_branch != 0) evt_pfmetSig();
  if (evt_pfmetSignificance_branch != 0) evt_pfmetSignificance();
  if (pfjets_muonE_branch != 0) pfjets_muonE();
  if (pfjets_photonE_branch != 0) pfjets_photonE();
  if (evt_lumiBlock_branch != 0) evt_lumiBlock();
  if (evt_pileup_branch != 0) evt_pileup();
  if (pfjets_electronE_branch != 0) pfjets_electronE();
  if (evt_pfmet_PhotonEnDown_branch != 0) evt_pfmet_PhotonEnDown();
  if (pfjets_area_branch != 0) pfjets_area();
  if (evt_pfmet_JetEnDown_branch != 0) evt_pfmet_JetEnDown();
  if (evt_pfmetPhi_TauEnDown_branch != 0) evt_pfmetPhi_TauEnDown();
  if (evt_pfmet_UnclusteredEnUp_branch != 0) evt_pfmet_UnclusteredEnUp();
  if (evt_pfmet_TauEnUp_branch != 0) evt_pfmet_TauEnUp();
  if (evt_pfmetPhi_PhotonEnUp_branch != 0) evt_pfmetPhi_PhotonEnUp();
  if (evt_event_branch != 0) evt_event();
  if (evt_pfmetPhi_JetEnUp_branch != 0) evt_pfmetPhi_JetEnUp();
  if (pfjets_hadronFlavour_branch != 0) pfjets_hadronFlavour();
  if (evt_pfmet_ElectronEnUp_branch != 0) evt_pfmet_ElectronEnUp();
  if (evt_CMS3tag_branch != 0) evt_CMS3tag();
  if (evt_isRealData_branch != 0) evt_isRealData();
  if (evt_pfmet_branch != 0) evt_pfmet();
  if (evt_pfmetPhi_ElectronEnUp_branch != 0) evt_pfmetPhi_ElectronEnUp();
}
const float &CMS3::evt_pfmet_JetResDown() {
  if (not evt_pfmet_JetResDown_isLoaded) {
    if (evt_pfmet_JetResDown_branch != 0) {
      evt_pfmet_JetResDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_JetResDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_JetResDown_isLoaded = true;
  }
  return evt_pfmet_JetResDown_;
}
const vector<vector<float> > &CMS3::pfjets_pfcandsdxyError() {
  if (not pfjets_pfcandsdxyError_isLoaded) {
    if (pfjets_pfcandsdxyError_branch != 0) {
      pfjets_pfcandsdxyError_branch->GetEntry(index);
    } else {
      printf("branch pfjets_pfcandsdxyError_branch does not exist!\n");
      exit(1);
    }
    pfjets_pfcandsdxyError_isLoaded = true;
  }
  return pfjets_pfcandsdxyError_;
}
const float &CMS3::evt_pfmetPhi_PhotonEnDown() {
  if (not evt_pfmetPhi_PhotonEnDown_isLoaded) {
    if (evt_pfmetPhi_PhotonEnDown_branch != 0) {
      evt_pfmetPhi_PhotonEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_PhotonEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_PhotonEnDown_isLoaded = true;
  }
  return evt_pfmetPhi_PhotonEnDown_;
}
const vector<vector<int> > &CMS3::pfjets_pfcandsid() {
  if (not pfjets_pfcandsid_isLoaded) {
    if (pfjets_pfcandsid_branch != 0) {
      pfjets_pfcandsid_branch->GetEntry(index);
    } else {
      printf("branch pfjets_pfcandsid_branch does not exist!\n");
      exit(1);
    }
    pfjets_pfcandsid_isLoaded = true;
  }
  return pfjets_pfcandsid_;
}
const vector<int> &CMS3::pfjets_partonFlavour() {
  if (not pfjets_partonFlavour_isLoaded) {
    if (pfjets_partonFlavour_branch != 0) {
      pfjets_partonFlavour_branch->GetEntry(index);
    } else {
      printf("branch pfjets_partonFlavour_branch does not exist!\n");
      exit(1);
    }
    pfjets_partonFlavour_isLoaded = true;
  }
  return pfjets_partonFlavour_;
}
const float &CMS3::evt_calomet() {
  if (not evt_calomet_isLoaded) {
    if (evt_calomet_branch != 0) {
      evt_calomet_branch->GetEntry(index);
    } else {
      printf("branch evt_calomet_branch does not exist!\n");
      exit(1);
    }
    evt_calomet_isLoaded = true;
  }
  return evt_calomet_;
}
const vector<int> &CMS3::genps_id_mother() {
  if (not genps_id_mother_isLoaded) {
    if (genps_id_mother_branch != 0) {
      genps_id_mother_branch->GetEntry(index);
    } else {
      printf("branch genps_id_mother_branch does not exist!\n");
      exit(1);
    }
    genps_id_mother_isLoaded = true;
  }
  return genps_id_mother_;
}
const float &CMS3::evt_pfmet_JetResUp() {
  if (not evt_pfmet_JetResUp_isLoaded) {
    if (evt_pfmet_JetResUp_branch != 0) {
      evt_pfmet_JetResUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_JetResUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_JetResUp_isLoaded = true;
  }
  return evt_pfmet_JetResUp_;
}
const vector<int> &CMS3::genps_status() {
  if (not genps_status_isLoaded) {
    if (genps_status_branch != 0) {
      genps_status_branch->GetEntry(index);
    } else {
      printf("branch genps_status_branch does not exist!\n");
      exit(1);
    }
    genps_status_isLoaded = true;
  }
  return genps_status_;
}
const vector<int> &CMS3::genps_id() {
  if (not genps_id_isLoaded) {
    if (genps_id_branch != 0) {
      genps_id_branch->GetEntry(index);
    } else {
      printf("branch genps_id_branch does not exist!\n");
      exit(1);
    }
    genps_id_isLoaded = true;
  }
  return genps_id_;
}
const float &CMS3::evt_pfmet_TauEnDown() {
  if (not evt_pfmet_TauEnDown_isLoaded) {
    if (evt_pfmet_TauEnDown_branch != 0) {
      evt_pfmet_TauEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_TauEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_TauEnDown_isLoaded = true;
  }
  return evt_pfmet_TauEnDown_;
}
const vector<float> &CMS3::pfjets_chargedEmE() {
  if (not pfjets_chargedEmE_isLoaded) {
    if (pfjets_chargedEmE_branch != 0) {
      pfjets_chargedEmE_branch->GetEntry(index);
    } else {
      printf("branch pfjets_chargedEmE_branch does not exist!\n");
      exit(1);
    }
    pfjets_chargedEmE_isLoaded = true;
  }
  return pfjets_chargedEmE_;
}
const float &CMS3::evt_pfmet_raw() {
  if (not evt_pfmet_raw_isLoaded) {
    if (evt_pfmet_raw_branch != 0) {
      evt_pfmet_raw_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_raw_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_raw_isLoaded = true;
  }
  return evt_pfmet_raw_;
}
const vector<float> &CMS3::pfjets_chargedHadronE() {
  if (not pfjets_chargedHadronE_isLoaded) {
    if (pfjets_chargedHadronE_branch != 0) {
      pfjets_chargedHadronE_branch->GetEntry(index);
    } else {
      printf("branch pfjets_chargedHadronE_branch does not exist!\n");
      exit(1);
    }
    pfjets_chargedHadronE_isLoaded = true;
  }
  return pfjets_chargedHadronE_;
}
const unsigned int &CMS3::evt_detectorStatus() {
  if (not evt_detectorStatus_isLoaded) {
    if (evt_detectorStatus_branch != 0) {
      evt_detectorStatus_branch->GetEntry(index);
    } else {
      printf("branch evt_detectorStatus_branch does not exist!\n");
      exit(1);
    }
    evt_detectorStatus_isLoaded = true;
  }
  return evt_detectorStatus_;
}
const float &CMS3::evt_pfmet_MuonEnUp() {
  if (not evt_pfmet_MuonEnUp_isLoaded) {
    if (evt_pfmet_MuonEnUp_branch != 0) {
      evt_pfmet_MuonEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_MuonEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_MuonEnUp_isLoaded = true;
  }
  return evt_pfmet_MuonEnUp_;
}
const float &CMS3::gen_metPhi() {
  if (not gen_metPhi_isLoaded) {
    if (gen_metPhi_branch != 0) {
      gen_metPhi_branch->GetEntry(index);
    } else {
      printf("branch gen_metPhi_branch does not exist!\n");
      exit(1);
    }
    gen_metPhi_isLoaded = true;
  }
  return gen_metPhi_;
}
const float &CMS3::evt_calometPhi() {
  if (not evt_calometPhi_isLoaded) {
    if (evt_calometPhi_branch != 0) {
      evt_calometPhi_branch->GetEntry(index);
    } else {
      printf("branch evt_calometPhi_branch does not exist!\n");
      exit(1);
    }
    evt_calometPhi_isLoaded = true;
  }
  return evt_calometPhi_;
}
const float &CMS3::evt_instantLumi() {
  if (not evt_instantLumi_isLoaded) {
    if (evt_instantLumi_branch != 0) {
      evt_instantLumi_branch->GetEntry(index);
    } else {
      printf("branch evt_instantLumi_branch does not exist!\n");
      exit(1);
    }
    evt_instantLumi_isLoaded = true;
  }
  return evt_instantLumi_;
}
const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &CMS3::pfjets_pfcandsp4() {
  if (not pfjets_pfcandsp4_isLoaded) {
    if (pfjets_pfcandsp4_branch != 0) {
      pfjets_pfcandsp4_branch->GetEntry(index);
    } else {
      printf("branch pfjets_pfcandsp4_branch does not exist!\n");
      exit(1);
    }
    pfjets_pfcandsp4_isLoaded = true;
  }
  return pfjets_pfcandsp4_;
}
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::pfjets_p4() {
  if (not pfjets_p4_isLoaded) {
    if (pfjets_p4_branch != 0) {
      pfjets_p4_branch->GetEntry(index);
    } else {
      printf("branch pfjets_p4_branch does not exist!\n");
      exit(1);
    }
    pfjets_p4_isLoaded = true;
  }
  return pfjets_p4_;
}
const float &CMS3::evt_pfsumet() {
  if (not evt_pfsumet_isLoaded) {
    if (evt_pfsumet_branch != 0) {
      evt_pfsumet_branch->GetEntry(index);
    } else {
      printf("branch evt_pfsumet_branch does not exist!\n");
      exit(1);
    }
    evt_pfsumet_isLoaded = true;
  }
  return evt_pfsumet_;
}
const vector<float> &CMS3::pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag() {
  if (not pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag_isLoaded) {
    if (pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag_branch != 0) {
      pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag_branch->GetEntry(index);
    } else {
      printf("branch pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag_branch does not exist!\n");
      exit(1);
    }
    pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag_isLoaded = true;
  }
  return pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag_;
}
const int &CMS3::evt_bunchCrossing() {
  if (not evt_bunchCrossing_isLoaded) {
    if (evt_bunchCrossing_branch != 0) {
      evt_bunchCrossing_branch->GetEntry(index);
    } else {
      printf("branch evt_bunchCrossing_branch does not exist!\n");
      exit(1);
    }
    evt_bunchCrossing_isLoaded = true;
  }
  return evt_bunchCrossing_;
}
const float &CMS3::evt_pfmetPhi() {
  if (not evt_pfmetPhi_isLoaded) {
    if (evt_pfmetPhi_branch != 0) {
      evt_pfmetPhi_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_isLoaded = true;
  }
  return evt_pfmetPhi_;
}
const float &CMS3::evt_pfsumet_raw() {
  if (not evt_pfsumet_raw_isLoaded) {
    if (evt_pfsumet_raw_branch != 0) {
      evt_pfsumet_raw_branch->GetEntry(index);
    } else {
      printf("branch evt_pfsumet_raw_branch does not exist!\n");
      exit(1);
    }
    evt_pfsumet_raw_isLoaded = true;
  }
  return evt_pfsumet_raw_;
}
const float &CMS3::evt_pfmetPhi_raw() {
  if (not evt_pfmetPhi_raw_isLoaded) {
    if (evt_pfmetPhi_raw_branch != 0) {
      evt_pfmetPhi_raw_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_raw_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_raw_isLoaded = true;
  }
  return evt_pfmetPhi_raw_;
}
const float &CMS3::evt_pfmetPhi_JetResUp() {
  if (not evt_pfmetPhi_JetResUp_isLoaded) {
    if (evt_pfmetPhi_JetResUp_branch != 0) {
      evt_pfmetPhi_JetResUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_JetResUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_JetResUp_isLoaded = true;
  }
  return evt_pfmetPhi_JetResUp_;
}
const vector<vector<float> > &CMS3::pfjets_pfcandsdzError() {
  if (not pfjets_pfcandsdzError_isLoaded) {
    if (pfjets_pfcandsdzError_branch != 0) {
      pfjets_pfcandsdzError_branch->GetEntry(index);
    } else {
      printf("branch pfjets_pfcandsdzError_branch does not exist!\n");
      exit(1);
    }
    pfjets_pfcandsdzError_isLoaded = true;
  }
  return pfjets_pfcandsdzError_;
}
const float &CMS3::evt_bField() {
  if (not evt_bField_isLoaded) {
    if (evt_bField_branch != 0) {
      evt_bField_branch->GetEntry(index);
    } else {
      printf("branch evt_bField_branch does not exist!\n");
      exit(1);
    }
    evt_bField_isLoaded = true;
  }
  return evt_bField_;
}
const vector<ULong64_t> &CMS3::evt_timestamp() {
  if (not evt_timestamp_isLoaded) {
    if (evt_timestamp_branch != 0) {
      evt_timestamp_branch->GetEntry(index);
    } else {
      printf("branch evt_timestamp_branch does not exist!\n");
      exit(1);
    }
    evt_timestamp_isLoaded = true;
  }
  return evt_timestamp_;
}
const vector<float> &CMS3::pfjets_pileupJetId() {
  if (not pfjets_pileupJetId_isLoaded) {
    if (pfjets_pileupJetId_branch != 0) {
      pfjets_pileupJetId_branch->GetEntry(index);
    } else {
      printf("branch pfjets_pileupJetId_branch does not exist!\n");
      exit(1);
    }
    pfjets_pileupJetId_isLoaded = true;
  }
  return pfjets_pileupJetId_;
}
const int &CMS3::evt_storeNumber() {
  if (not evt_storeNumber_isLoaded) {
    if (evt_storeNumber_branch != 0) {
      evt_storeNumber_branch->GetEntry(index);
    } else {
      printf("branch evt_storeNumber_branch does not exist!\n");
      exit(1);
    }
    evt_storeNumber_isLoaded = true;
  }
  return evt_storeNumber_;
}
const vector<float> &CMS3::pfjets_undoJEC() {
  if (not pfjets_undoJEC_isLoaded) {
    if (pfjets_undoJEC_branch != 0) {
      pfjets_undoJEC_branch->GetEntry(index);
    } else {
      printf("branch pfjets_undoJEC_branch does not exist!\n");
      exit(1);
    }
    pfjets_undoJEC_isLoaded = true;
  }
  return pfjets_undoJEC_;
}
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::genps_p4() {
  if (not genps_p4_isLoaded) {
    if (genps_p4_branch != 0) {
      genps_p4_branch->GetEntry(index);
    } else {
      printf("branch genps_p4_branch does not exist!\n");
      exit(1);
    }
    genps_p4_isLoaded = true;
  }
  return genps_p4_;
}
const float &CMS3::evt_lumiRun() {
  if (not evt_lumiRun_isLoaded) {
    if (evt_lumiRun_branch != 0) {
      evt_lumiRun_branch->GetEntry(index);
    } else {
      printf("branch evt_lumiRun_branch does not exist!\n");
      exit(1);
    }
    evt_lumiRun_isLoaded = true;
  }
  return evt_lumiRun_;
}
const float &CMS3::evt_pfmetPhi_JetResDown() {
  if (not evt_pfmetPhi_JetResDown_isLoaded) {
    if (evt_pfmetPhi_JetResDown_branch != 0) {
      evt_pfmetPhi_JetResDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_JetResDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_JetResDown_isLoaded = true;
  }
  return evt_pfmetPhi_JetResDown_;
}
const float &CMS3::evt_lumiFill() {
  if (not evt_lumiFill_isLoaded) {
    if (evt_lumiFill_branch != 0) {
      evt_lumiFill_branch->GetEntry(index);
    } else {
      printf("branch evt_lumiFill_branch does not exist!\n");
      exit(1);
    }
    evt_lumiFill_isLoaded = true;
  }
  return evt_lumiFill_;
}
const vector<float> &CMS3::pfjets_neutralEmE() {
  if (not pfjets_neutralEmE_isLoaded) {
    if (pfjets_neutralEmE_branch != 0) {
      pfjets_neutralEmE_branch->GetEntry(index);
    } else {
      printf("branch pfjets_neutralEmE_branch does not exist!\n");
      exit(1);
    }
    pfjets_neutralEmE_isLoaded = true;
  }
  return pfjets_neutralEmE_;
}
const unsigned int &CMS3::evt_run() {
  if (not evt_run_isLoaded) {
    if (evt_run_branch != 0) {
      evt_run_branch->GetEntry(index);
    } else {
      printf("branch evt_run_branch does not exist!\n");
      exit(1);
    }
    evt_run_isLoaded = true;
  }
  return evt_run_;
}
const float &CMS3::evt_pfmetPhi_MuonEnDown() {
  if (not evt_pfmetPhi_MuonEnDown_isLoaded) {
    if (evt_pfmetPhi_MuonEnDown_branch != 0) {
      evt_pfmetPhi_MuonEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_MuonEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_MuonEnDown_isLoaded = true;
  }
  return evt_pfmetPhi_MuonEnDown_;
}
const int &CMS3::evt_orbitNumber() {
  if (not evt_orbitNumber_isLoaded) {
    if (evt_orbitNumber_branch != 0) {
      evt_orbitNumber_branch->GetEntry(index);
    } else {
      printf("branch evt_orbitNumber_branch does not exist!\n");
      exit(1);
    }
    evt_orbitNumber_isLoaded = true;
  }
  return evt_orbitNumber_;
}
const float &CMS3::evt_pfmetPhi_ElectronEnDown() {
  if (not evt_pfmetPhi_ElectronEnDown_isLoaded) {
    if (evt_pfmetPhi_ElectronEnDown_branch != 0) {
      evt_pfmetPhi_ElectronEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_ElectronEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_ElectronEnDown_isLoaded = true;
  }
  return evt_pfmetPhi_ElectronEnDown_;
}
const int &CMS3::evt_experimentType() {
  if (not evt_experimentType_isLoaded) {
    if (evt_experimentType_branch != 0) {
      evt_experimentType_branch->GetEntry(index);
    } else {
      printf("branch evt_experimentType_branch does not exist!\n");
      exit(1);
    }
    evt_experimentType_isLoaded = true;
  }
  return evt_experimentType_;
}
const float &CMS3::evt_pfmet_MuonEnDown() {
  if (not evt_pfmet_MuonEnDown_isLoaded) {
    if (evt_pfmet_MuonEnDown_branch != 0) {
      evt_pfmet_MuonEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_MuonEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_MuonEnDown_isLoaded = true;
  }
  return evt_pfmet_MuonEnDown_;
}
const float &CMS3::evt_pfmetPhi_UnclusteredEnDown() {
  if (not evt_pfmetPhi_UnclusteredEnDown_isLoaded) {
    if (evt_pfmetPhi_UnclusteredEnDown_branch != 0) {
      evt_pfmetPhi_UnclusteredEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_UnclusteredEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_UnclusteredEnDown_isLoaded = true;
  }
  return evt_pfmetPhi_UnclusteredEnDown_;
}
const float &CMS3::evt_pfmetPhi_UnclusteredEnUp() {
  if (not evt_pfmetPhi_UnclusteredEnUp_isLoaded) {
    if (evt_pfmetPhi_UnclusteredEnUp_branch != 0) {
      evt_pfmetPhi_UnclusteredEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_UnclusteredEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_UnclusteredEnUp_isLoaded = true;
  }
  return evt_pfmetPhi_UnclusteredEnUp_;
}
const float &CMS3::evt_pfmet_PhotonEnUp() {
  if (not evt_pfmet_PhotonEnUp_isLoaded) {
    if (evt_pfmet_PhotonEnUp_branch != 0) {
      evt_pfmet_PhotonEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_PhotonEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_PhotonEnUp_isLoaded = true;
  }
  return evt_pfmet_PhotonEnUp_;
}
const float &CMS3::evt_pileupRMS() {
  if (not evt_pileupRMS_isLoaded) {
    if (evt_pileupRMS_branch != 0) {
      evt_pileupRMS_branch->GetEntry(index);
    } else {
      printf("branch evt_pileupRMS_branch does not exist!\n");
      exit(1);
    }
    evt_pileupRMS_isLoaded = true;
  }
  return evt_pileupRMS_;
}
const float &CMS3::evt_pfmetPhi_MuonEnUp() {
  if (not evt_pfmetPhi_MuonEnUp_isLoaded) {
    if (evt_pfmetPhi_MuonEnUp_branch != 0) {
      evt_pfmetPhi_MuonEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_MuonEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_MuonEnUp_isLoaded = true;
  }
  return evt_pfmetPhi_MuonEnUp_;
}
const float &CMS3::evt_pfmetPhi_JetEnDown() {
  if (not evt_pfmetPhi_JetEnDown_isLoaded) {
    if (evt_pfmetPhi_JetEnDown_branch != 0) {
      evt_pfmetPhi_JetEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_JetEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_JetEnDown_isLoaded = true;
  }
  return evt_pfmetPhi_JetEnDown_;
}
const float &CMS3::evt_pfmet_ElectronEnDown() {
  if (not evt_pfmet_ElectronEnDown_isLoaded) {
    if (evt_pfmet_ElectronEnDown_branch != 0) {
      evt_pfmet_ElectronEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_ElectronEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_ElectronEnDown_isLoaded = true;
  }
  return evt_pfmet_ElectronEnDown_;
}
const vector<float> &CMS3::pfjets_neutralHadronE() {
  if (not pfjets_neutralHadronE_isLoaded) {
    if (pfjets_neutralHadronE_branch != 0) {
      pfjets_neutralHadronE_branch->GetEntry(index);
    } else {
      printf("branch pfjets_neutralHadronE_branch does not exist!\n");
      exit(1);
    }
    pfjets_neutralHadronE_isLoaded = true;
  }
  return pfjets_neutralHadronE_;
}
const vector<vector<float> > &CMS3::pfjets_pfcandsdz() {
  if (not pfjets_pfcandsdz_isLoaded) {
    if (pfjets_pfcandsdz_branch != 0) {
      pfjets_pfcandsdz_branch->GetEntry(index);
    } else {
      printf("branch pfjets_pfcandsdz_branch does not exist!\n");
      exit(1);
    }
    pfjets_pfcandsdz_isLoaded = true;
  }
  return pfjets_pfcandsdz_;
}
const vector<vector<bool> > &CMS3::pfjets_pfcandshighPurity() {
  if (not pfjets_pfcandshighPurity_isLoaded) {
    if (pfjets_pfcandshighPurity_branch != 0) {
      pfjets_pfcandshighPurity_branch->GetEntry(index);
    } else {
      printf("branch pfjets_pfcandshighPurity_branch does not exist!\n");
      exit(1);
    }
    pfjets_pfcandshighPurity_isLoaded = true;
  }
  return pfjets_pfcandshighPurity_;
}
const vector<TString> &CMS3::evt_dataset() {
  if (not evt_dataset_isLoaded) {
    if (evt_dataset_branch != 0) {
      evt_dataset_branch->GetEntry(index);
    } else {
      printf("branch evt_dataset_branch does not exist!\n");
      exit(1);
    }
    evt_dataset_isLoaded = true;
  }
  return evt_dataset_;
}
const vector<vector<float> > &CMS3::pfjets_pfcandsdxy() {
  if (not pfjets_pfcandsdxy_isLoaded) {
    if (pfjets_pfcandsdxy_branch != 0) {
      pfjets_pfcandsdxy_branch->GetEntry(index);
    } else {
      printf("branch pfjets_pfcandsdxy_branch does not exist!\n");
      exit(1);
    }
    pfjets_pfcandsdxy_isLoaded = true;
  }
  return pfjets_pfcandsdxy_;
}
const float &CMS3::evt_pfmet_UnclusteredEnDown() {
  if (not evt_pfmet_UnclusteredEnDown_isLoaded) {
    if (evt_pfmet_UnclusteredEnDown_branch != 0) {
      evt_pfmet_UnclusteredEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_UnclusteredEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_UnclusteredEnDown_isLoaded = true;
  }
  return evt_pfmet_UnclusteredEnDown_;
}
const float &CMS3::evt_pfmetPhi_TauEnUp() {
  if (not evt_pfmetPhi_TauEnUp_isLoaded) {
    if (evt_pfmetPhi_TauEnUp_branch != 0) {
      evt_pfmetPhi_TauEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_TauEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_TauEnUp_isLoaded = true;
  }
  return evt_pfmetPhi_TauEnUp_;
}
const float &CMS3::evt_pfmet_JetEnUp() {
  if (not evt_pfmet_JetEnUp_isLoaded) {
    if (evt_pfmet_JetEnUp_branch != 0) {
      evt_pfmet_JetEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_JetEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_JetEnUp_isLoaded = true;
  }
  return evt_pfmet_JetEnUp_;
}
const float &CMS3::gen_met() {
  if (not gen_met_isLoaded) {
    if (gen_met_branch != 0) {
      gen_met_branch->GetEntry(index);
    } else {
      printf("branch gen_met_branch does not exist!\n");
      exit(1);
    }
    gen_met_isLoaded = true;
  }
  return gen_met_;
}
const float &CMS3::evt_instantLumiErr() {
  if (not evt_instantLumiErr_isLoaded) {
    if (evt_instantLumiErr_branch != 0) {
      evt_instantLumiErr_branch->GetEntry(index);
    } else {
      printf("branch evt_instantLumiErr_branch does not exist!\n");
      exit(1);
    }
    evt_instantLumiErr_isLoaded = true;
  }
  return evt_instantLumiErr_;
}
const float &CMS3::evt_pfmetSig() {
  if (not evt_pfmetSig_isLoaded) {
    if (evt_pfmetSig_branch != 0) {
      evt_pfmetSig_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetSig_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetSig_isLoaded = true;
  }
  return evt_pfmetSig_;
}
const float &CMS3::evt_pfmetSignificance() {
  if (not evt_pfmetSignificance_isLoaded) {
    if (evt_pfmetSignificance_branch != 0) {
      evt_pfmetSignificance_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetSignificance_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetSignificance_isLoaded = true;
  }
  return evt_pfmetSignificance_;
}
const vector<float> &CMS3::pfjets_muonE() {
  if (not pfjets_muonE_isLoaded) {
    if (pfjets_muonE_branch != 0) {
      pfjets_muonE_branch->GetEntry(index);
    } else {
      printf("branch pfjets_muonE_branch does not exist!\n");
      exit(1);
    }
    pfjets_muonE_isLoaded = true;
  }
  return pfjets_muonE_;
}
const vector<float> &CMS3::pfjets_photonE() {
  if (not pfjets_photonE_isLoaded) {
    if (pfjets_photonE_branch != 0) {
      pfjets_photonE_branch->GetEntry(index);
    } else {
      printf("branch pfjets_photonE_branch does not exist!\n");
      exit(1);
    }
    pfjets_photonE_isLoaded = true;
  }
  return pfjets_photonE_;
}
const unsigned int &CMS3::evt_lumiBlock() {
  if (not evt_lumiBlock_isLoaded) {
    if (evt_lumiBlock_branch != 0) {
      evt_lumiBlock_branch->GetEntry(index);
    } else {
      printf("branch evt_lumiBlock_branch does not exist!\n");
      exit(1);
    }
    evt_lumiBlock_isLoaded = true;
  }
  return evt_lumiBlock_;
}
const float &CMS3::evt_pileup() {
  if (not evt_pileup_isLoaded) {
    if (evt_pileup_branch != 0) {
      evt_pileup_branch->GetEntry(index);
    } else {
      printf("branch evt_pileup_branch does not exist!\n");
      exit(1);
    }
    evt_pileup_isLoaded = true;
  }
  return evt_pileup_;
}
const vector<float> &CMS3::pfjets_electronE() {
  if (not pfjets_electronE_isLoaded) {
    if (pfjets_electronE_branch != 0) {
      pfjets_electronE_branch->GetEntry(index);
    } else {
      printf("branch pfjets_electronE_branch does not exist!\n");
      exit(1);
    }
    pfjets_electronE_isLoaded = true;
  }
  return pfjets_electronE_;
}
const float &CMS3::evt_pfmet_PhotonEnDown() {
  if (not evt_pfmet_PhotonEnDown_isLoaded) {
    if (evt_pfmet_PhotonEnDown_branch != 0) {
      evt_pfmet_PhotonEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_PhotonEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_PhotonEnDown_isLoaded = true;
  }
  return evt_pfmet_PhotonEnDown_;
}
const vector<float> &CMS3::pfjets_area() {
  if (not pfjets_area_isLoaded) {
    if (pfjets_area_branch != 0) {
      pfjets_area_branch->GetEntry(index);
    } else {
      printf("branch pfjets_area_branch does not exist!\n");
      exit(1);
    }
    pfjets_area_isLoaded = true;
  }
  return pfjets_area_;
}
const float &CMS3::evt_pfmet_JetEnDown() {
  if (not evt_pfmet_JetEnDown_isLoaded) {
    if (evt_pfmet_JetEnDown_branch != 0) {
      evt_pfmet_JetEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_JetEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_JetEnDown_isLoaded = true;
  }
  return evt_pfmet_JetEnDown_;
}
const float &CMS3::evt_pfmetPhi_TauEnDown() {
  if (not evt_pfmetPhi_TauEnDown_isLoaded) {
    if (evt_pfmetPhi_TauEnDown_branch != 0) {
      evt_pfmetPhi_TauEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_TauEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_TauEnDown_isLoaded = true;
  }
  return evt_pfmetPhi_TauEnDown_;
}
const float &CMS3::evt_pfmet_UnclusteredEnUp() {
  if (not evt_pfmet_UnclusteredEnUp_isLoaded) {
    if (evt_pfmet_UnclusteredEnUp_branch != 0) {
      evt_pfmet_UnclusteredEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_UnclusteredEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_UnclusteredEnUp_isLoaded = true;
  }
  return evt_pfmet_UnclusteredEnUp_;
}
const float &CMS3::evt_pfmet_TauEnUp() {
  if (not evt_pfmet_TauEnUp_isLoaded) {
    if (evt_pfmet_TauEnUp_branch != 0) {
      evt_pfmet_TauEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_TauEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_TauEnUp_isLoaded = true;
  }
  return evt_pfmet_TauEnUp_;
}
const float &CMS3::evt_pfmetPhi_PhotonEnUp() {
  if (not evt_pfmetPhi_PhotonEnUp_isLoaded) {
    if (evt_pfmetPhi_PhotonEnUp_branch != 0) {
      evt_pfmetPhi_PhotonEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_PhotonEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_PhotonEnUp_isLoaded = true;
  }
  return evt_pfmetPhi_PhotonEnUp_;
}
const ULong64_t &CMS3::evt_event() {
  if (not evt_event_isLoaded) {
    if (evt_event_branch != 0) {
      evt_event_branch->GetEntry(index);
    } else {
      printf("branch evt_event_branch does not exist!\n");
      exit(1);
    }
    evt_event_isLoaded = true;
  }
  return evt_event_;
}
const float &CMS3::evt_pfmetPhi_JetEnUp() {
  if (not evt_pfmetPhi_JetEnUp_isLoaded) {
    if (evt_pfmetPhi_JetEnUp_branch != 0) {
      evt_pfmetPhi_JetEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_JetEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_JetEnUp_isLoaded = true;
  }
  return evt_pfmetPhi_JetEnUp_;
}
const vector<int> &CMS3::pfjets_hadronFlavour() {
  if (not pfjets_hadronFlavour_isLoaded) {
    if (pfjets_hadronFlavour_branch != 0) {
      pfjets_hadronFlavour_branch->GetEntry(index);
    } else {
      printf("branch pfjets_hadronFlavour_branch does not exist!\n");
      exit(1);
    }
    pfjets_hadronFlavour_isLoaded = true;
  }
  return pfjets_hadronFlavour_;
}
const float &CMS3::evt_pfmet_ElectronEnUp() {
  if (not evt_pfmet_ElectronEnUp_isLoaded) {
    if (evt_pfmet_ElectronEnUp_branch != 0) {
      evt_pfmet_ElectronEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_ElectronEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_ElectronEnUp_isLoaded = true;
  }
  return evt_pfmet_ElectronEnUp_;
}
const vector<TString> &CMS3::evt_CMS3tag() {
  if (not evt_CMS3tag_isLoaded) {
    if (evt_CMS3tag_branch != 0) {
      evt_CMS3tag_branch->GetEntry(index);
    } else {
      printf("branch evt_CMS3tag_branch does not exist!\n");
      exit(1);
    }
    evt_CMS3tag_isLoaded = true;
  }
  return evt_CMS3tag_;
}
const int &CMS3::evt_isRealData() {
  if (not evt_isRealData_isLoaded) {
    if (evt_isRealData_branch != 0) {
      evt_isRealData_branch->GetEntry(index);
    } else {
      printf("branch evt_isRealData_branch does not exist!\n");
      exit(1);
    }
    evt_isRealData_isLoaded = true;
  }
  return evt_isRealData_;
}
const float &CMS3::evt_pfmet() {
  if (not evt_pfmet_isLoaded) {
    if (evt_pfmet_branch != 0) {
      evt_pfmet_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_isLoaded = true;
  }
  return evt_pfmet_;
}
const float &CMS3::evt_pfmetPhi_ElectronEnUp() {
  if (not evt_pfmetPhi_ElectronEnUp_isLoaded) {
    if (evt_pfmetPhi_ElectronEnUp_branch != 0) {
      evt_pfmetPhi_ElectronEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_ElectronEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_ElectronEnUp_isLoaded = true;
  }
  return evt_pfmetPhi_ElectronEnUp_;
}
void CMS3::progress( int nEventsTotal, int nEventsChain ){
  int period = 1000;
  if(nEventsTotal%1000 == 0) {
    if (isatty(1)) {
      if( ( nEventsChain - nEventsTotal ) > period ){
        float frac = (float)nEventsTotal/(nEventsChain*0.01);
        printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
               "\033[0m\033[32m <---\033[0m\015", frac);
        fflush(stdout);
      }
      else {
        printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
               "\033[0m\033[32m <---\033[0m\015", 100.);
        cout << endl;
      }
    }
  }
}
namespace tas {
  const float &evt_pfmet_JetResDown() { return cms3.evt_pfmet_JetResDown(); }
  const vector<vector<float> > &pfjets_pfcandsdxyError() { return cms3.pfjets_pfcandsdxyError(); }
  const float &evt_pfmetPhi_PhotonEnDown() { return cms3.evt_pfmetPhi_PhotonEnDown(); }
  const vector<vector<int> > &pfjets_pfcandsid() { return cms3.pfjets_pfcandsid(); }
  const vector<int> &pfjets_partonFlavour() { return cms3.pfjets_partonFlavour(); }
  const float &evt_calomet() { return cms3.evt_calomet(); }
  const vector<int> &genps_id_mother() { return cms3.genps_id_mother(); }
  const float &evt_pfmet_JetResUp() { return cms3.evt_pfmet_JetResUp(); }
  const vector<int> &genps_status() { return cms3.genps_status(); }
  const vector<int> &genps_id() { return cms3.genps_id(); }
  const float &evt_pfmet_TauEnDown() { return cms3.evt_pfmet_TauEnDown(); }
  const vector<float> &pfjets_chargedEmE() { return cms3.pfjets_chargedEmE(); }
  const float &evt_pfmet_raw() { return cms3.evt_pfmet_raw(); }
  const vector<float> &pfjets_chargedHadronE() { return cms3.pfjets_chargedHadronE(); }
  const unsigned int &evt_detectorStatus() { return cms3.evt_detectorStatus(); }
  const float &evt_pfmet_MuonEnUp() { return cms3.evt_pfmet_MuonEnUp(); }
  const float &gen_metPhi() { return cms3.gen_metPhi(); }
  const float &evt_calometPhi() { return cms3.evt_calometPhi(); }
  const float &evt_instantLumi() { return cms3.evt_instantLumi(); }
  const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &pfjets_pfcandsp4() { return cms3.pfjets_pfcandsp4(); }
  const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfjets_p4() { return cms3.pfjets_p4(); }
  const float &evt_pfsumet() { return cms3.evt_pfsumet(); }
  const vector<float> &pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag() { return cms3.pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag(); }
  const int &evt_bunchCrossing() { return cms3.evt_bunchCrossing(); }
  const float &evt_pfmetPhi() { return cms3.evt_pfmetPhi(); }
  const float &evt_pfsumet_raw() { return cms3.evt_pfsumet_raw(); }
  const float &evt_pfmetPhi_raw() { return cms3.evt_pfmetPhi_raw(); }
  const float &evt_pfmetPhi_JetResUp() { return cms3.evt_pfmetPhi_JetResUp(); }
  const vector<vector<float> > &pfjets_pfcandsdzError() { return cms3.pfjets_pfcandsdzError(); }
  const float &evt_bField() { return cms3.evt_bField(); }
  const vector<ULong64_t> &evt_timestamp() { return cms3.evt_timestamp(); }
  const vector<float> &pfjets_pileupJetId() { return cms3.pfjets_pileupJetId(); }
  const int &evt_storeNumber() { return cms3.evt_storeNumber(); }
  const vector<float> &pfjets_undoJEC() { return cms3.pfjets_undoJEC(); }
  const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genps_p4() { return cms3.genps_p4(); }
  const float &evt_lumiRun() { return cms3.evt_lumiRun(); }
  const float &evt_pfmetPhi_JetResDown() { return cms3.evt_pfmetPhi_JetResDown(); }
  const float &evt_lumiFill() { return cms3.evt_lumiFill(); }
  const vector<float> &pfjets_neutralEmE() { return cms3.pfjets_neutralEmE(); }
  const unsigned int &evt_run() { return cms3.evt_run(); }
  const float &evt_pfmetPhi_MuonEnDown() { return cms3.evt_pfmetPhi_MuonEnDown(); }
  const int &evt_orbitNumber() { return cms3.evt_orbitNumber(); }
  const float &evt_pfmetPhi_ElectronEnDown() { return cms3.evt_pfmetPhi_ElectronEnDown(); }
  const int &evt_experimentType() { return cms3.evt_experimentType(); }
  const float &evt_pfmet_MuonEnDown() { return cms3.evt_pfmet_MuonEnDown(); }
  const float &evt_pfmetPhi_UnclusteredEnDown() { return cms3.evt_pfmetPhi_UnclusteredEnDown(); }
  const float &evt_pfmetPhi_UnclusteredEnUp() { return cms3.evt_pfmetPhi_UnclusteredEnUp(); }
  const float &evt_pfmet_PhotonEnUp() { return cms3.evt_pfmet_PhotonEnUp(); }
  const float &evt_pileupRMS() { return cms3.evt_pileupRMS(); }
  const float &evt_pfmetPhi_MuonEnUp() { return cms3.evt_pfmetPhi_MuonEnUp(); }
  const float &evt_pfmetPhi_JetEnDown() { return cms3.evt_pfmetPhi_JetEnDown(); }
  const float &evt_pfmet_ElectronEnDown() { return cms3.evt_pfmet_ElectronEnDown(); }
  const vector<float> &pfjets_neutralHadronE() { return cms3.pfjets_neutralHadronE(); }
  const vector<vector<float> > &pfjets_pfcandsdz() { return cms3.pfjets_pfcandsdz(); }
  const vector<vector<bool> > &pfjets_pfcandshighPurity() { return cms3.pfjets_pfcandshighPurity(); }
  const vector<TString> &evt_dataset() { return cms3.evt_dataset(); }
  const vector<vector<float> > &pfjets_pfcandsdxy() { return cms3.pfjets_pfcandsdxy(); }
  const float &evt_pfmet_UnclusteredEnDown() { return cms3.evt_pfmet_UnclusteredEnDown(); }
  const float &evt_pfmetPhi_TauEnUp() { return cms3.evt_pfmetPhi_TauEnUp(); }
  const float &evt_pfmet_JetEnUp() { return cms3.evt_pfmet_JetEnUp(); }
  const float &gen_met() { return cms3.gen_met(); }
  const float &evt_instantLumiErr() { return cms3.evt_instantLumiErr(); }
  const float &evt_pfmetSig() { return cms3.evt_pfmetSig(); }
  const float &evt_pfmetSignificance() { return cms3.evt_pfmetSignificance(); }
  const vector<float> &pfjets_muonE() { return cms3.pfjets_muonE(); }
  const vector<float> &pfjets_photonE() { return cms3.pfjets_photonE(); }
  const unsigned int &evt_lumiBlock() { return cms3.evt_lumiBlock(); }
  const float &evt_pileup() { return cms3.evt_pileup(); }
  const vector<float> &pfjets_electronE() { return cms3.pfjets_electronE(); }
  const float &evt_pfmet_PhotonEnDown() { return cms3.evt_pfmet_PhotonEnDown(); }
  const vector<float> &pfjets_area() { return cms3.pfjets_area(); }
  const float &evt_pfmet_JetEnDown() { return cms3.evt_pfmet_JetEnDown(); }
  const float &evt_pfmetPhi_TauEnDown() { return cms3.evt_pfmetPhi_TauEnDown(); }
  const float &evt_pfmet_UnclusteredEnUp() { return cms3.evt_pfmet_UnclusteredEnUp(); }
  const float &evt_pfmet_TauEnUp() { return cms3.evt_pfmet_TauEnUp(); }
  const float &evt_pfmetPhi_PhotonEnUp() { return cms3.evt_pfmetPhi_PhotonEnUp(); }
  const ULong64_t &evt_event() { return cms3.evt_event(); }
  const float &evt_pfmetPhi_JetEnUp() { return cms3.evt_pfmetPhi_JetEnUp(); }
  const vector<int> &pfjets_hadronFlavour() { return cms3.pfjets_hadronFlavour(); }
  const float &evt_pfmet_ElectronEnUp() { return cms3.evt_pfmet_ElectronEnUp(); }
  const vector<TString> &evt_CMS3tag() { return cms3.evt_CMS3tag(); }
  const int &evt_isRealData() { return cms3.evt_isRealData(); }
  const float &evt_pfmet() { return cms3.evt_pfmet(); }
  const float &evt_pfmetPhi_ElectronEnUp() { return cms3.evt_pfmetPhi_ElectronEnUp(); }
}
