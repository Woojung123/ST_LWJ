

#include "PreCompile.h"
#include "DarkTB.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"


DarkTB::DarkTB()
	: Speed(50.0f)
	, Renderer(nullptr)
	, BiconRenderer(nullptr)
	, Reach(200.f)
	, AttCheck(false)
	, AttTimeMax(0.8f)
	, AttTime(0.f)
	, ListLastCheck(false)
	, AttCount(0)
	, AttCountMax(5)
	, m_Dir({ 0 })
	, BAniChange(false)
{
}

DarkTB::~DarkTB()
{
}


void DarkTB::AttEnd(const FrameAnimation_DESC& _Info)
{
	AttCheck = true;
	Renderer->ChangeFrameAnimation("DarkTStand12");
}

void DarkTB::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 64.f,64.f,1.f });


		Renderer->CreateFrameAnimationFolder("DarkTAttack0", FrameAnimation_DESC("DarkTAttack0", 0.1f));
		Renderer->CreateFrameAnimationFolder("DarkTAttack1", FrameAnimation_DESC("DarkTAttack1", 0.1f));
		Renderer->CreateFrameAnimationFolder("DarkTAttack2", FrameAnimation_DESC("DarkTAttack2", 0.1f));
		Renderer->CreateFrameAnimationFolder("DarkTAttack3", FrameAnimation_DESC("DarkTAttack3", 0.1f));
		Renderer->CreateFrameAnimationFolder("DarkTAttack4", FrameAnimation_DESC("DarkTAttack4", 0.1f));
		Renderer->CreateFrameAnimationFolder("DarkTAttack5", FrameAnimation_DESC("DarkTAttack5", 0.1f));
		Renderer->CreateFrameAnimationFolder("DarkTAttack6", FrameAnimation_DESC("DarkTAttack6", 0.1f));
		Renderer->CreateFrameAnimationFolder("DarkTAttack7", FrameAnimation_DESC("DarkTAttack7", 0.1f));
		Renderer->CreateFrameAnimationFolder("DarkTAttack8", FrameAnimation_DESC("DarkTAttack8", 0.1f));
		Renderer->CreateFrameAnimationFolder("DarkTAttack9", FrameAnimation_DESC("DarkTAttack9", 0.1f));
		Renderer->CreateFrameAnimationFolder("DarkTAttack10", FrameAnimation_DESC("DarkTAttack10", 0.1f));
		Renderer->CreateFrameAnimationFolder("DarkTAttack11", FrameAnimation_DESC("DarkTAttack11", 0.1f));
		Renderer->CreateFrameAnimationFolder("DarkTAttack12", FrameAnimation_DESC("DarkTAttack12", 0.1f));
		Renderer->CreateFrameAnimationFolder("DarkTAttack13", FrameAnimation_DESC("DarkTAttack13", 0.1f));
		Renderer->CreateFrameAnimationFolder("DarkTAttack14", FrameAnimation_DESC("DarkTAttack14", 0.1f));
		Renderer->CreateFrameAnimationFolder("DarkTAttack15", FrameAnimation_DESC("DarkTAttack15", 0.1f));

		Renderer->CreateFrameAnimationFolder("DarkTStand12", FrameAnimation_DESC("DarkTStand12", 0.1f));

		Renderer->ChangeFrameAnimation("DarkTStand12");


		Renderer->AnimationBindEnd("DarkTAttack0", &DarkTB::AttEnd, this);
		Renderer->AnimationBindEnd("DarkTAttack1", &DarkTB::AttEnd, this);
		Renderer->AnimationBindEnd("DarkTAttack2", &DarkTB::AttEnd, this);
		Renderer->AnimationBindEnd("DarkTAttack3", &DarkTB::AttEnd, this);
		Renderer->AnimationBindEnd("DarkTAttack4", &DarkTB::AttEnd, this);
		Renderer->AnimationBindEnd("DarkTAttack5", &DarkTB::AttEnd, this);
		Renderer->AnimationBindEnd("DarkTAttack6", &DarkTB::AttEnd, this);
		Renderer->AnimationBindEnd("DarkTAttack7", &DarkTB::AttEnd, this);
		Renderer->AnimationBindEnd("DarkTAttack8", &DarkTB::AttEnd, this);
		Renderer->AnimationBindEnd("DarkTAttack9", &DarkTB::AttEnd, this);
		Renderer->AnimationBindEnd("DarkTAttack10", &DarkTB::AttEnd, this);
		Renderer->AnimationBindEnd("DarkTAttack11", &DarkTB::AttEnd, this);
		Renderer->AnimationBindEnd("DarkTAttack12", &DarkTB::AttEnd, this);
		Renderer->AnimationBindEnd("DarkTAttack13", &DarkTB::AttEnd, this);
		Renderer->AnimationBindEnd("DarkTAttack14", &DarkTB::AttEnd, this);
		Renderer->AnimationBindEnd("DarkTAttack15", &DarkTB::AttEnd, this);

	}

	{
		BiconRenderer = CreateComponent<GameEngineTextureRenderer>();
		BiconRenderer->SetTexture("beacon.png");
		BiconRenderer->ScaleToTexture();
		float4 RenderWorldPos = BiconRenderer->GetTransform().GetWorldPosition();
		BiconRenderer->GetTransform().SetWorldPosition({ RenderWorldPos.x - 5.f, RenderWorldPos.y - 5.f , 1.f });
	}



}

void DarkTB::Update(float _DeltaTime)
{
	//Renderer->ChangeFrameAnimation("DragonAttack15");
	std::list<GameEngineActor*> Group = GetLevel()->GetGroup(OBJECTORDER::Monster);

	int Monsize = (int)Group.size();
	int MonCount = 0;
	AttCount = 0;
	AttCountMax = 3;

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

				((UnitBase*)TarGet)->m_Info.m_Hp -= 50;

			}
			break;
		}


		if (MonCount == Monsize)
		{
			AttCheck = false;
			BAniChange = false;
			Renderer->ChangeFrameAnimation("DarkTStand12");
			AttTime = 0.f;
		}


	}



	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });


}


void DarkTB::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;




	if (m_fAngle >= 349.f || m_fAngle < 11.5f)
	{
		Renderer->ChangeFrameAnimation("DarkTAttack0");
	}

	if (m_fAngle >= 11.5 && m_fAngle < 34.f)
	{
		Renderer->ChangeFrameAnimation("DarkTAttack1");
	}

	if (m_fAngle >= 34.f && m_fAngle < 56.5f)
	{
		Renderer->ChangeFrameAnimation("DarkTAttack2");
	}

	if (m_fAngle >= 56.5f && m_fAngle < 79.f)
	{
		Renderer->ChangeFrameAnimation("DarkTAttack3");
	}

	if (m_fAngle >= 79.f && m_fAngle < 101.5f)
	{
		Renderer->ChangeFrameAnimation("DarkTAttack4");
	}

	if (m_fAngle >= 101.5f && m_fAngle < 124.f)
	{
		Renderer->ChangeFrameAnimation("DarkTAttack5");
	}

	if (m_fAngle >= 124.f && m_fAngle < 146.5f)
	{
		Renderer->ChangeFrameAnimation("DarkTAttack6");
	}

	if (m_fAngle >= 146.5f && m_fAngle < 169.f)
	{
		Renderer->ChangeFrameAnimation("DarkTAttack7");
	}

	if (m_fAngle >= 169.f && m_fAngle < 191.5f)
	{
		Renderer->ChangeFrameAnimation("DarkTAttack8");
	}

	if (m_fAngle >= 191.5f && m_fAngle < 214.f)
	{
		Renderer->ChangeFrameAnimation("DarkTAttack9");
	}

	if (m_fAngle >= 214.f && m_fAngle < 236.5f)
	{
		Renderer->ChangeFrameAnimation("DarkTAttack10");
	}

	if (m_fAngle > 236.5f && m_fAngle < 259.f)
	{
		Renderer->ChangeFrameAnimation("DarkTAttack11");
	}

	if (m_fAngle >= 259.f && m_fAngle < 281.5f) //Down
	{
		Renderer->ChangeFrameAnimation("DarkTAttack12");
	}

	if (m_fAngle >= 281.5f && m_fAngle < 304.f)
	{
		Renderer->ChangeFrameAnimation("DarkTAttack13");
	}

	if (m_fAngle >= 304.5f && m_fAngle < 326.5f)
	{
		Renderer->ChangeFrameAnimation("DarkTAttack14");
	}

	if (m_fAngle >= 326.5f && m_fAngle < 349.f)
	{
		Renderer->ChangeFrameAnimation("DarkTAttack15");
	}


}
