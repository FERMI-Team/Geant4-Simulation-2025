#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}


G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
	G4NistManager *nist = G4NistManager::Instance();
	
	G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR"); //materiale
	
	G4MaterialPropertiesTable *mptWorld = new G4MaterialPropertiesTable();
	mptWorld->AddProperty("RINDEX", energy, rindexWorld, 2);
	
	worldMat->SetMaterialPropertiesTable(mptWorld);
	
	G4Box *solidWorld = new G4Box("solidWorld", 0.05*m, 0.05*m, 0.05*m); //solid volume lato 10 cm)
	
	G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
	
	G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);
	
	
	G4Box *solidRadiator = new G4Box("solidRadiator", 0.02*m, 0.02*m, 0.02*m); //cubo lato 4cm
	
	G4LogicalVolume *logicRadiator = new G4LogicalVolume(solidRadiator, iron, "logicalRadiator");
	
	G4VPhysicalVolume *physRadiator = new G4PVPlacement(0, G4ThreeVector(0., 0., 27), logicRadiator, "physRadiator", logicWorld, false, 0, true); //in mm
	
	G4Box *solidDetector = new G4Box("solidDetector", 0.5, 0.5, 0.1); //in mm
	
	logicDetector = new G4LogicalVolume(solidDetector, worldMat, "logicDetector");
	
	for(G4int i = 0; i < 100; i++)
	{
	for (G4int j = 0; j < 100; j++)
	{
	G4VPhysicalVolume *physDetector = new G4PVPlacement(0, G4ThreeVector(-0.05*m+(i+0.05)*m/1000, -0.05*m+(j+0.05)*m/1000, 0.049*m), logicDetector, "physDetector", logicWorld, false, j+i*1000, true);
	}
	}
	
	return physWorld;
	

}

void MyDetectorConstruction::ConstructSDandField()
{
MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");

logicDetector->SetSensitiveDetector(sensDet);
}

