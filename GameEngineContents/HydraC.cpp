

#include "PreCompile.h"
#include "HydraC.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"Sunken.h"

HydraC::HydraC()
	: Speed(50.0f)
	, Renderer(nullptr)
	, Reach(150.f)
	, TestUni(nullptr)
	, AttCheck(false)
	, AttTimeMax(0.4f)
	, AttTime(0.f)
	, ListLastCheck(false)
	, m_Dir({ 0 })
	,BAniChange(false)
{
}

HydraC::~HydraC()
{
}


void HydraC::AttEnd(const FrameAnimation_DESC& _Info)
{
	AttCheck = true;
	Renderer->ChangeFrameAnimation("hidraMove12");

}


void HydraC::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 128.f,128.f,1.f });
		
		Renderer->CreateFrameAnimationFolder("hidraAttack0", FrameAnimation_DESC("hidraAttack0", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack1", FrameAnimation_DESC("hidraAttack1", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack2", FrameAnimation_DESC("hidraAttack2", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack3", FrameAnimation_DESC("hidraAttack3", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack4", FrameAnimation_DESC("hidraAttack4", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack5", FrameAnimation_DESC("hidraAttack5", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack6", FrameAnimation_DESC("hidraAttack6", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack7", FrameAnimation_DESC("hidraAttack7", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack8", FrameAnimation_DESC("hidraAttack8", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack9", FrameAnimation_DESC("hidraAttack9", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack10", FrameAnimation_DESC("hidraAttack10", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack11", FrameAnimation_DESC("hidraAttack11", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack12", FrameAnimation_DESC("hidraAttack12", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack13", FrameAnimation_DESC("hidraAttack13", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack14", FrameAnimation_DESC("hidraAttack14", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack15", FrameAnimation_DESC("hidraAttack15", 0.1f));

		Renderer->CreateFrameAnimationFolder("hidraMove12", FrameAnimation_DESC("hidraMove12", 0.1f));

		Renderer->ChangeFrameAnimation("hidraMove12");


		Renderer->AnimationBindEnd("hidraAttack0", &HydraC::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack1", &HydraC::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack2", &HydraC::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack3", &HydraC::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack4", &HydraC::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack5", &HydraC::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack6", &HydraC::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack7", &HydraC::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack8", &HydraC::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack9", &HydraC::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack10", &HydraC::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack11", &HydraC::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack12", &HydraC::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack13", &HydraC::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack14", &HydraC::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack15", &HydraC::AttEnd, this);

	}
}

void HydraC::Update(float _DeltaTime)
{
	//Renderer->ChangeFrameAnimation("DragonAttack15");
	std::list<GameEngineActor*> Group = GetLevel()->GetGroup(OBJECTORDER::Monster);

	int Monsize = (int)(Group.size());
	int MonCount = 0;

	auto	iter = Group.begin();
	auto	iterEnd = Group.end();

	for (; iter != iterEnd; ++iter)
	{
		GameEngineActor* TarGet = (*iter);
		float4 TarGetPos = TarGet->GetTransform().GetWorldPosition();
		float4 MyPos = GetTransform().GetWorldPosition();
		float4 Dist = MyPos - TarGetPos;
		float MonLen = Dist.Length();

		++MonCount;

		if (MonLen <= Reach)
		{

			if (!BAniChange)
			{
				m_Dir = (TarGetPos - MyPos);
				m_Dir.Normalize();

				ChangeAni(TarGetPos, MyPos);
				BAniChange = true;
			}

			if (AttCheck)
			{

				AttCheck = false;
				BAniChange = false;
				TestUni = GetLevel()->CreateActor<Sunken>(OBJECTORDER::Bullet);
				TestUni->GetTransform().SetWorldPosition(TarGetPos);
				TestUni->TarGet = TarGet;

			}


			break;
		}

		if (MonCount == Monsize)
		{
			AttCheck = false;
			BAniChange = false;
			Renderer->ChangeFrameAnimation("hidraMove12");
			AttTime = 0.f;
		}


	}


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });




}

void HydraC::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;




	if (m_fAngle >= 349.f || m_fAngle < 11.5f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack0");
	}

	if (m_fAngle >= 11.5 && m_fAngle < 34.f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack1");
	}

	if (m_fAngle >= 34.f && m_fAngle < 56.5f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack2");
	}

	if (m_fAngle >= 56.5f && m_fAngle < 79.f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack3");
	}

	if (m_fAngle >= 79.f && m_fAngle < 101.5f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack4");
	}

	if (m_fAngle >= 101.5f && m_fAngle < 124.f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack5");
	}

	if (m_fAngle >= 124.f && m_fAngle < 146.5f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack6");
	}

	if (m_fAngle >= 146.5f && m_fAngle < 169.f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack7");
	}

	if (m_fAngle >= 169.f && m_fAngle < 191.5f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack8");
	}

	if (m_fAngle >= 191.5f && m_fAngle < 214.f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack9");
	}

	if (m_fAngle >= 214.f && m_fAngle < 236.5f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack10");
	}

	if (m_fAngle > 236.5f && m_fAngle < 259.f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack11");
	}

	if (m_fAngle >= 259.f && m_fAngle < 281.5f) //Down
	{
		Renderer->ChangeFrameAnimation("hidraAttack12");
	}

	if (m_fAngle >= 281.5f && m_fAngle < 304.f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack13");
	}

	if (m_fAngle >= 304.5f && m_fAngle < 326.5f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack14");
	}

	if (m_fAngle >= 326.5f && m_fAngle < 349.f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack15");
	}


}
