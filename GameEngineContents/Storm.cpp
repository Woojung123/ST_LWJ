

#include "PreCompile.h"
#include "Storm.h"
#include "GlobalContentsValue.h"
#include <GameEngineCore/GameEngineLevel.h>



Storm::Storm()
	: Speed(1000.0f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, TarGet(nullptr)
	, m_dotDam(0.f)
	, BAniChange(false)
{
}

Storm::~Storm()
{
	Death();
}


void Storm::AttEnd(const FrameAnimation_DESC& _Info)
{
	BAniChange = true;

}


void Storm::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 224.f,224.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("storm", FrameAnimation_DESC("storm", 0.1f));
		Renderer->ChangeFrameAnimation("storm");

		Renderer->AnimationBindEnd("storm", &Storm::AttEnd, this);
	}

	m_Info.Dammage = 20;

}

void Storm::Update(float _DeltaTime)
{
	if (BAniChange)
		Death();


	//if (TarGet)
	//{
	//	/*float4 TargetPos = TarGet->GetTransform().GetWorldPosition();
	//	TargetPos.z = -45.f;
	//	GetTransform().SetWorldPosition(TargetPos);

	//	m_dotDam += _DeltaTime;

	//	if (m_dotDam >= 1.f)
	//	{
	//		m_dotDam -= 1.f;
	//		((UnitBase*)TarGet)->m_Info.m_Hp -= 5;

	//	}*/

	//}
	//else
	//{
	//	Death();
	//	return;
	//}


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -45.f, WorldPos.w });


}