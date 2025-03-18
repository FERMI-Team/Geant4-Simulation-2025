#include "physics.hh"

// Riusltano errore linee di codice G4Muons (esclusa rica 7 e 17)

MyPhysicsList::MyPhysicsList()
{
RegisterPhysics (new G4EmStandardPhysics());

//RegisterPhysics (new G4MuonDecayChannelWithSpin());
//RegisterPhysics (new G4MuonMinusCapture());

//RegisterPhysics (new G4MuonMinusBoundDecay());
//RegisterPhysics (new G4MuBetheBlochModel());
//RegisterPhysics (new G4MuBremsstrahlungModel());
//RegisterPhysics (new G4MuonicAtomDecay());
RegisterPhysics (new G4MuonicAtomDecayPhysics());
//RegisterPhysics (new G4MuonicAtomHelper());
//RegisterPhysics (new G4MuonMinusAtomicCapture());
}

void MyPhysicsList::ConstructParticles()
{
G4MuonMinus::MuonMinusDefinition();
G4MuonPlus::MuonPlusDefinition();
}

MyPhysicsList::~MyPhysicsList()
{}
