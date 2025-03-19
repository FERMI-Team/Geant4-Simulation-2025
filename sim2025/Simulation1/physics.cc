#include "physics.hh"

FisicaMuoni::FisicaMuoni(const G4String&) 
{

}

FisicaMuoni::~FisicaMuoni()
{}

void FisicaMuoni::ConstructParticle() 
{

}

void FisicaMuoni::ConstructProcess()
{

}

MyPhysicsList::MyPhysicsList()
{
RegisterPhysics (new G4EmStandardPhysics());

//RegisterPhysics (new G4MuonDecayChannelWithSpin());
//RegisterPhysics (new G4MuonMinusCapture()); E' UN PROCESSO

//RegisterPhysics (new G4MuonMinusBoundDecay());
//RegisterPhysics (new G4MuBetheBlochModel()); E' UN PROCESSO
//RegisterPhysics (new G4MuBremsstrahlungModel()); E' UN PROCESSO
//RegisterPhysics (new G4MuonicAtomDecay()); DOVREBBE ESSERE UN PROCESSO
RegisterPhysics (new G4MuonicAtomDecayPhysics());
//RegisterPhysics (new G4MuonicAtomHelper());
//RegisterPhysics (new G4MuonMinusAtomicCapture()); DOVREBBE ESSERE UN PROCESSO
}

MyPhysicsList::~MyPhysicsList()
{}
