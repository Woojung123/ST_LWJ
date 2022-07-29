
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
		Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		Renderer->GetTransform().SetLocalPosition({ 300, 300, 1 });
	}
}
