#ifndef PHYSICS_HH
#define PHYSICS_HH

#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4MuonMinus.hh"
#include "G4MuonPlus.hh"
#include "G4MuonDecayChannelWithSpin.hh"
#include "G4MuonMinusCapture.hh"

#include "G4MuonMinusBoundDecay.hh"
#include "G4MuBetheBlochModel.hh"
#include "G4MuBremsstrahlungModel.hh"
#include "G4MuonicAtomDecay.hh"
#include "G4MuonicAtomDecayPhysics.hh"
#include "G4MuonicAtomHelper.hh"
#include "G4MuonMinusAtomicCapture.hh"

#include "G4VPhysicsConstructor.hh"
#include "G4ProcessManager.hh"

class FisicaMuoni : public G4VPhysicsConstructor
{
public:

	FisicaMuoni();
	~FisicaMuoni();

	void ConstructParticle() override;
	void ConstructProcess() override;
};


class MyPhysicsList : public  G4VModularPhysicsList

{
public:
	MyPhysicsList();
	~MyPhysicsList();
};

#endif
