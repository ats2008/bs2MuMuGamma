#ifndef TREECONTENT_H
#define TREECONTENT_H

#include <vector>
#include <string>
#include "TTree.h"

#include "miniB0KstarMuMu/miniKstarMuMu/interface/miniHLTObj.h"



class TreeContent
{
 public:
  
   TreeContent ();
  ~TreeContent ();

  void Init ();
  void ClearNTuple ();
  void ClearMonteCarlo ();
  void MakeTreeBranches (TTree* theTree);


  // ########################################################
  // # Run Number, event number, #reco vtx and event weight #
  // ########################################################
  unsigned int              runN;
  unsigned int              eventN;
  unsigned int              recoVtxN;
  double                    evWeight;
  double                    evWeightE2;
  unsigned int              numEventsTried;
  unsigned int              numEventsPassed;


  // ###########
  // # Trigger #
  // ###########
  std::vector<std::string>  *TrigTable;
  std::vector<int>          *TrigPrescales;
  std::vector<std::string>  *L1Table;
  std::vector<int>          *L1Prescales;

  
  
  // ###########################
  // # Number of B0 candidates #
  // ###########################
  unsigned int              nB;
  
  // ############################
  // # Pileup information in MC #
  // ############################
  std::vector<double>       *bunchXingMC, *numInteractionsMC, *trueNumInteractionsMC;
  // Comment:
  // - PileupSummaryInfo::getTrueNumInteractions() gives the distribution of the mean number of interactions per crossing.
  // Since this is the mean value of the poisson distribution from which the number of interactions in- and out-of-time are
  // generated, no additional information should be required for reweighting if these values are matched in data and Monte Carlo.
  // - PileupSummaryInfo::getPU_NumInteractions() gives the expected mean number of interactions per crossing for each LumiSection.
  // Therefore the pileup histogram will contain the distribution of the number of interactions one would actually observe given
  // a poisson of that mean. So, this distribution is what one would see if one counted the number of events seen in a given beam
  // crossing (by looking at the number of vertices in data, for example. This would be appropriate for pileup reweighting based
  // on in-time-only distributions.

  // ################################
  // # Primary Vertex and Beam Spot #
  // ################################
  double                    bsX, bsY;

  
  // # reco::Muons #
  
  std::vector<double>   *muon_pt, *muon_eta, *muon_phi, *mum_dz, *muon_dxy;
  std::vector<double>   *muon_pt_error, *muon_eta_error, *muon_phi_error, *mum_dz_error, *muon_dxy_error;
  std::vector<double>   *muon_vx,*muon_vy,*muon_vz,*muon_vertexChi2,*muon_vertexNDoF;

  std::vector<int>	*muon_charge;
  std::vector<bool>	*muon_isGlobal,*muon_isTracker,*muon_StandAloneMuon,*isCaloMuon,*muon_isPFMuon;
  int 	            	*nMuons;

  std::vector<uint64_t> *muon_selector; 
  std::vector<bool>	*muon_isIsolationValid;
  std::vector<reco::MuonIsolation> *muon_isolation03,*muon_isolation05;
  
  void ClearScalars ();
  void ClearScalarsMonteCarlo ();
  void ClearVectors ();
  void ClearVectorsMonteCarlo ();
};

#endif
