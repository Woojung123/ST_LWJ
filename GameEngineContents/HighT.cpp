


#include "PreCompile.h"
#include "HighT.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"Storm.h"

HighT::HighT()
	: Speed(50.0f)
	, Renderer(nullptr)
	, BiconRenderer(nullptr)
	, Reach(200.f)
	, TestUni(nullptr)
	, AttCheck(false)
	, AttTimeMax(0.4f)
	, AttTime(0.f)
	, ListLastCheck(false)
	, m_Dir({ 0 })
	, BAniChange(false)
	, BATTDelayTime(false)
	, FATTDelayTime(0.f)
{
}

HighT::~HighT()
{
}


void HighT::AttEnd(const FrameAnimation_DESC& _Info)
{
	//AttCheck = true;
	Renderer->ChangeFrameAnimation("hitemplerMove12");
	BATTDelayTime = true;

}


void HighT::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 128.f,128.f,1.f });

		Renderer->CreateFrameAnimationFolder("hitemplerAttack0", FrameAnimation_DESC("hitemplerAttack0", 0.1f));
		Renderer->CreateFrameAnimationFolder("hitemplerAttack1", FrameAnimation_DESC("hitemplerAttack1", 0.1f));
		Renderer->CreateFrameAnimationFolder("hitemplerAttack2", FrameAnimation_DESC("hitemplerAttack2", 0.1f));
		Renderer->CreateFrameAnimationFolder("hitemplerAttack3", FrameAnimation_DESC("hitemplerAttack3", 0.1f));
		Renderer->CreateFrameAnimationFolder("hitemplerAttack4", FrameAnimation_DESC("hitemplerAttack4", 0.1f));
		Renderer->CreateFrameAnimationFolder("hitemplerAttack5", FrameAnimation_DESC("hitemplerAttack5", 0.1f));
		Renderer->CreateFrameAnimationFolder("hitemplerAttack6", FrameAnimation_DESC("hitemplerAttack6", 0.1f));
		Renderer->CreateFrameAnimationFolder("hitemplerAttack7", FrameAnimation_DESC("hitemplerAttack7", 0.1f));
		Renderer->CreateFrameAnimationFolder("hitemplerAttack8", FrameAnimation_DESC("hitemplerAttack8", 0.1f));
		Renderer->CreateFrameAnimationFolder("hitemplerAttack9", FrameAnimation_DESC("hitemplerAttack9", 0.1f));
		Renderer->CreateFrameAnimationFolder("hitemplerAttack10", FrameAnimation_DESC("hitemplerAttack10", 0.1f));
		Renderer->CreateFrameAnimationFolder("hitemplerAttack11", FrameAnimation_DESC("hitemplerAttack11", 0.1f));
		Renderer->CreateFrameAnimationFolder("hitemplerAttack12", FrameAnimation_DESC("hitemplerAttack12", 0.1f));
		Renderer->CreateFrameAnimationFolder("hitemplerAttack13", FrameAnimation_DESC("hitemplerAttack13", 0.1f));
		Renderer->CreateFrameAnimationFolder("hitemplerAttack14", FrameAnimation_DESC("hitemplerAttack14", 0.1f));
		Renderer->CreateFrameAnimationFolder("hitemplerAttack15", FrameAnimation_DESC("hitemplerAttack15", 0.1f));
		
		Renderer->CreateFrameAnimationFolder("hitemplerMove12", FrameAnimation_DESC("hitemplerMove12", 0.1f));

		Renderer->ChangeFrameAnimation("hitemplerMove12");


		Renderer->AnimationBindEnd("hitemplerAttack0", &HighT::AttEnd, this);
		Renderer->AnimationBindEnd("hitemplerAttack1", &HighT::AttEnd, this);
		Renderer->AnimationBindEnd("hitemplerAttack2", &HighT::AttEnd, this);
		Renderer->AnimationBindEnd("hitemplerAttack3", &HighT::AttEnd, this);
		Renderer->AnimationBindEnd("hitemplerAttack4", &HighT::AttEnd, this);
		Renderer->AnimationBindEnd("hitemplerAttack5", &HighT::AttEnd, this);
		Renderer->AnimationBindEnd("hitemplerAttack6", &HighT::AttEnd, this);
		Renderer->AnimationBindEnd("hitemplerAttack7", &HighT::AttEnd, this);
		Renderer->AnimationBindEnd("hitemplerAttack8", &HighT::AttEnd, this);
		Renderer->AnimationBindEnd("hitemplerAttack9", &HighT::AttEnd, this);
		Renderer->AnimationBindEnd("hitemplerAttack10", &HighT::AttEnd, this);
		Renderer->AnimationBindEnd("hitemplerAttack11", &HighT::AttEnd, this);
		Renderer->AnimationBindEnd("hitemplerAttack12", &HighT::AttEnd, this);
		Renderer->AnimationBindEnd("hitemplerAttack13", &HighT::AttEnd, this);
		Renderer->AnimationBindEnd("hitemplerAttack14", &HighT::AttEnd, this);
		Renderer->AnimationBindEnd("hitemplerAttack15", &HighT::AttEnd, this);

	}


	{
		BiconRenderer = CreateComponent<GameEngineTextureRenderer>();
		BiconRenderer->SetTexture("beacon.png");
		BiconRenderer->ScaleToTexture();
		float4 RenderWorldPos = BiconRenderer->GetTransform().GetWorldPosition();
		BiconRenderer->GetTransform().SetWorldPosition({ RenderWorldPos.x - 5.f, RenderWorldPos.y - 5.f , 1.f });
	}


}

void HighT::Update(float _DeltaTime)
{
	

	if (BATTDelayTime)
	{
		FATTDelayTime += _DeltaTime;

		if (FATTDelayTime >= 1.f)
		{
			AttCheck = true;
			FATTDelayTime = 0.f;
			BATTDelayTime = false;

		}
	}






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
				TestUni = GetLevel()->CreateActor<Storm>(OBJECTORDER::Bullet);
				TestUni->GetTransform().SetWorldPosition(TarGetPos);
				TestUni->TarGet = TarGet;

			}


			break;
		}

		if (MonCount == Monsize)
		{
			AttCheck = false;
			BAniChange = false;
			Renderer->ChangeFrameAnimation("hitemplerMove12");
			AttTime = 0.f;
		}


	}


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });




}

void HighT::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;




	if (m_fAngle >= 349.f || m_fAngle < 11.5f)
	{
		Renderer->ChangeFrameAnimation("hitemplerAttack0");
	}

	if (m_fAngle >= 11.5 && m_fAngle < 34.f)
	{
		Renderer->ChangeFrameAnimation("hitemplerAttack1");
	}

	if (m_fAngle >= 34.f && m_fAngle < 56.5f)
	{
		Renderer->ChangeFrameAnimation("hitemplerAttack2");
	}

	if (m_fAngle >= 56.5f && m_fAngle < 79.f)
	{
		Renderer->ChangeFrameAnimation("hitemplerAttack3");
	}

	if (m_fAngle >= 79.f && m_fAngle < 101.5f)
	{
		Renderer->ChangeFrameAnimation("hitemplerAttack4");
	}

	if (m_fAngle >= 101.5f && m_fAngle < 124.f)
	{
		Renderer->ChangeFrameAnimation("hitemplerAttack5");
	}

	if (m_fAngle >= 124.f && m_fAngle < 146.5f)
	{
		Renderer->ChangeFrameAnimation("hitemplerAttack6");
	}

	if (m_fAngle >= 146.5f && m_fAngle < 169.f)
	{
		Renderer->ChangeFrameAnimation("hitemplerAttack7");
	}

	if (m_fAngle >= 169.f && m_fAngle < 191.5f)
	{
		Renderer->ChangeFrameAnimation("hitemplerAttack8");
	}

	if (m_fAngle >= 191.5f && m_fAngle < 214.f)
	{
		Renderer->ChangeFrameAnimation("hitemplerAttack9");
	}

	if (m_fAngle >= 214.f && m_fAngle < 236.5f)
	{
		Renderer->ChangeFrameAnimation("hitemplerAttack10");
	}

	if (m_fAngle > 236.5f && m_fAngle < 259.f)
	{
		Renderer->ChangeFrameAnimation("hitemplerAttack11");
	}

	if (m_fAngle >= 259.f && m_fAngle < 281.5f) //Down
	{
		Renderer->ChangeFrameAnimation("hitemplerAttack12");
	}

	if (m_fAngle >= 281.5f && m_fAngle < 304.f)
	{
		Renderer->ChangeFrameAnimation("hitemplerAttack13");
	}

	if (m_fAngle >= 304.5f && m_fAngle < 326.5f)
	{
		Renderer->ChangeFrameAnimation("hitemplerAttack14");
	}

	if (m_fAngle >= 326.5f && m_fAngle < 349.f)
	{
		Renderer->ChangeFrameAnimation("hitemplerAttack15");
	}


}
