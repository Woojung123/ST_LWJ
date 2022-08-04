
#include "PreCompile.h"
#include "TestUI.h"

TestUI::TestUI()
{
}

TestUI::~TestUI()
{
}

void TestUI::Start()
{
	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("Ui.png");
		Renderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		Renderer->GetTransform().SetLocalPosition({ 0, 0, -150 });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);
	}
}
