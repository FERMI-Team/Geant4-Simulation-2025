#include "physics.hh"

FisicaMuoni::FisicaMuoni() 
{}

FisicaMuoni::~FisicaMuoni()
{}

// Costruzione Particelle Non Presenti In G4EmPhysicsStandard

void FisicaMuoni::ConstructParticle() 
{
	G4NeutrinoMu::NeutrinoMuDefinition();
	G4NeutrinoE::NeutrinoEDefinition();
	G4AntiNeutrinoMu::AntiNeutrinoMuDefinition();
	G4AntiNeutrinoE::AntiNeutrinoEDefinition();
}
// Aggiunta a MuonMinus I Processi:  MuonMinusCapture, MuonMinusAtomicCapture

void FisicaMuoni::ConstructProcess() {

	G4ProcessManager* muMinusManager = G4MuonMinus::Definition()->GetProcessManager();
	muMinusManager->AddDiscreteProcess(new G4MuonMinusCapture());
	muMinusManager->AddDiscreteProcess(new G4MuonMinusAtomicCapture());
}

//- G4MuonicAtomDecay GIA DEFINITO IN MUONIC ATOMDECAYPHYSICS
//- G4MuonDecayChannelWithSpin() Non un processo
//- G4MuonMinusBoundDecay() Non un processo
//- G4MuBetheBlochModel()); Non un Processo
//- RegisterPhysics (new G4MuBremsstrahlungModel()); Non un processo


MyPhysicsList::MyPhysicsList()
{
	RegisterPhysics (new G4EmStandardPhysics()); 
	RegisterPhysics (new G4MuonicAtomDecayPhysics());
	RegisterPhysics (new FisicaMuoni());
}

MyPhysicsList::~MyPhysicsList()
{}