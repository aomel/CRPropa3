#ifndef _FOLD_H_
#define _FOLD_H_

#include "dint/rate.h"
#include "dint/cvector.h"

void InitializeLeptonCoefficients(TotalRate* leptonTotalRate,
				  DiffRate* leptonScatRate,
                                  DiffRate* leptonExchRate,
                                  DiffRate* leptonPhotonRate);
void InitializePhotonCoefficients(TotalRate* photonTotalRate,
                                  DiffRate* photonLeptonRate);
void InitializeNucleonCoefficients(TotalRate* protonTotalRate,
				   TotalRate* neutronTotalRate,
				   DiffRate* protonScatRate,
				   DiffRate* protonNeutronRate,
				   DiffRate* neutronProtonRate,
				   DiffRate* protonPhotonRate,
				   DiffRate* protonElectronRate,
				   DiffRate* protonPositronRate,
				   DiffRate* neutronElectronRate,
				   DiffRate* neutronPositronRate,
				   DiffRate* protonElectronNeutrinoRate,
				   DiffRate* protonAntiElectronNeutrinoRate,
				   DiffRate* protonMuonNeutrinoRate,
				   DiffRate* protonAntiMuonNeutrinoRate,
				   DiffRate* neutronAntiElectronNeutrinoRate,
				   DiffRate* neutronMuonNeutrinoRate,
				   DiffRate* neutronAntiMuonNeutrinoRate);
void InitializeNeutrinoCoefficients(TotalRate* elNeutTotalRate,
				    TotalRate* muonNeutTotalRate,
				    TotalRate* tauNeutTotalRate,
				    DiffRate* elNeutScatRate,
				    DiffRate* elNeutMuonNeutRate,
				    DiffRate* elNeutTauNeutRate,
				    DiffRate* elNeutElectronRate,
				    DiffRate* elNeutPhotonRate,
				    DiffRate* elNeutProtonRate,
				    DiffRate* muonNeutElNeutRate,
				    DiffRate* muonNeutScatRate,
				    DiffRate* muonNeutTauNeutRate,
				    DiffRate* muonNeutElectronRate,
				    DiffRate* muonNeutPhotonRate,
				    DiffRate* muonNeutProtonRate,
				    DiffRate* tauNeutElNeutRate,
				    DiffRate* tauNeutMuonNeutRate,
				    DiffRate* tauNeutScatRate,
				    DiffRate* tauNeutElectronRate,
				    DiffRate* tauNeutPhotonRate,
				    DiffRate* tauNeutProtonRate);
void FoldTotalRate(const dCVector* pBgPhotonDensity,
		   const RawTotalRate* pRawTotalRate, TotalRate* pTotalRate);
void FoldDiffRate(const dCVector* pBgPhotonDensity,
		  const RawDiffRate* pRawDiffRate,
		  DiffRate* pDiffRate, const int scatSwitch, ...);
void FoldICS(const dCVector* pBgPhotonDensity, 
	     const RawTotalRate* ICSTotalRate,
	     const RawDiffRate* ICSPhotonRate, const RawDiffRate* ICSScatRate,
	     TotalRate* leptonTotalRate, DiffRate* leptonPhotonRate,
             DiffRate* leptonScatRate);
void FoldTPP(const dCVector* pBgPhotonDensity, const dCVector* pEnergy,
	     const RawTotalRate* TPPTotalRate, const RawDiffRate* TPPDiffRate,
	     TotalRate* leptonTotalRate, DiffRate* leptonScatRate, 
	     DiffRate* leptonExchRate, dCVector* otherLoss);
void FoldPP(const dCVector* pBgPhotonDensity, const RawTotalRate* PPTotalRate,
	    const RawDiffRate* PPDiffRate, TotalRate* photonTotalRate, 
	    DiffRate* photonLeptonRate);
void FoldDPP(const dCVector* pBgPhotonDensity, const RawTotalRate* DPPRate,
	     TotalRate* photonTotalRate, DiffRate* photonLeptonRate);
void FoldPPPNucleon(const dCVector* pBgPhotonDensity, 
		    const RawTotalRate* PPPProtonLossRate,
		    const RawTotalRate* PPPNeutronLossRate, 
		    const RawDiffRate* PPPProtonScatRate,
		    const RawDiffRate* PPPProtonNeutronRate,
		    const RawDiffRate* PPPNeutronProtonRate,
		    TotalRate* protonTotalRate, TotalRate* neutronTotalRate,
		    DiffRate* protonScatRate, DiffRate* protonNeutronRate,
		    DiffRate* neutronProtonRate);
void FoldPPPSecondary(const dCVector* pBgPhotonDensity, 
		      const RawDiffRate* PPPProtonPhotonRate,
		      const RawDiffRate* PPPProtonElectronRate,
		      const RawDiffRate* PPPProtonPositronRate,
		      const RawDiffRate* PPPNeutronElectronRate,
		      const RawDiffRate* PPPProtonElectronNeutrinoRate,
		      const RawDiffRate* PPPProtonAntiElectronNeutrinoRate,
		      const RawDiffRate* PPPProtonMuonNeutrinoRate,
		      const RawDiffRate* PPPProtonAntiMuonNeutrinoRate,
		      const RawDiffRate* PPPNeutronAntiElectronNeutrinoRate,
		      const RawDiffRate* PPPNeutronMuonNeutrinoRate,
		      const RawDiffRate* PPPNeutronAntiMuonNeutrinoRate,
		      DiffRate* protonPhotonRate, 
		      DiffRate* protonElectronRate, 
		      DiffRate* protonPositronRate, 
		      DiffRate* neutronElectronRate, 
		      DiffRate* neutronPositronRate, 
		      DiffRate* protonElectronNeutrinoRate,
		      DiffRate* protonAntiElectronNeutrinoRate,
		      DiffRate* protonMuonNeutrinoRate,
		      DiffRate* protonAntiMuonNeutrinoRate,
		      DiffRate* neutronAntiElectronNeutrinoRate,
		      DiffRate* neutronMuonNeutrinoRate,
		      DiffRate* neutronAntiMuonNeutrinoRate);
void FoldNPPNucleon(const dCVector* pBgPhotonDensity, const dCVector* pEnergy,
		    const RawTotalRate* NPPTotalRate, 
		    dCVector* protonContinuousLoss);
void FoldNPPSecondary(const dCVector* pBgPhotonDensity, 
		      const RawDiffRate* NPPDiffRate, 
		      DiffRate* protonPositronRate, 
		      DiffRate* protonElectronRate);

void MapNeutTotalRate(const double redshift, const int lastIndex,
		      const int tauNeutrinoMassSwitch, 
		      const TotalRate* NNTotalRate, 
		      TotalRate* totalRate);
void MapNeutDiffRate(const double redshift, const int lastIndex,
		     const int tauNeutrinoMassSwitch, 
		     const DiffRate* NNDiffRate, 
		     DiffRate* diffRate);
void MapNeutRates(const double redshift, const int lastIndex,
		  const int tauNeutrinoMassSwitch,
		  const TotalRate* NNElNeutTotalRate,
		  const TotalRate* NNMuonNeutTotalRate,
		  const TotalRate* NNTauNeutTotalRate,
		  const DiffRate* NNElNeutScatRate, 
		  const DiffRate* NNElNeutMuonNeutRate,
		  const DiffRate* NNElNeutTauNeutRate,
		  const DiffRate* NNElNeutElectronRate,
		  const DiffRate* NNElNeutPhotonRate,
		  const DiffRate* NNElNeutProtonRate,
		  const DiffRate* NNMuonNeutElNeutRate,
		  const DiffRate* NNMuonNeutScatRate,
		  const DiffRate* NNMuonNeutTauNeutRate,
		  const DiffRate* NNMuonNeutElectronRate,
		  const DiffRate* NNMuonNeutPhotonRate,
		  const DiffRate* NNMuonNeutProtonRate,
		  const DiffRate* NNTauNeutElNeutRate, 
		  const DiffRate* NNTauNeutMuonNeutRate, 
		  const DiffRate* NNTauNeutScatRate, 
		  const DiffRate* NNTauNeutElectronRate, 
		  const DiffRate* NNTauNeutPhotonRate, 
		  const DiffRate* NNTauNeutProtonRate,
		  TotalRate* elNeutTotalRate, TotalRate* muonNeutTotalRate,
		  TotalRate* tauNeutTotalRate, DiffRate* elNeutScatRate, 
		  DiffRate* elNeutMuonNeutRate, DiffRate* elNeutTauNeutRate,
		  DiffRate* elNeutElectronRate, DiffRate* elNeutPhotonRate,
		  DiffRate* elNeutProtonRate, DiffRate* muonNeutElNeutRate,
		  DiffRate* muonNeutScatRate, DiffRate* muonNeutTauNeutRate,
		  DiffRate* muonNeutElectronRate, DiffRate* muonNeutPhotonRate,
		  DiffRate* muonNeutProtonRate, DiffRate* tauNeutElNeutRate, 
		  DiffRate* tauNeutMuonNeutRate, DiffRate* tauNeutScatRate, 
		  DiffRate* tauNeutElectronRate, DiffRate* tauNeutPhotonRate, 
		  DiffRate* tauNeutProtonRate);
#endif
