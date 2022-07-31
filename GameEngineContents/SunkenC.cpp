
#include "PreCompile.h"
#include "SunkenC.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"Sunken.h"

SunkenC::SunkenC()
	: Speed(50.0f)
	, Renderer(nullptr)
	, BiconRenderer(nullptr)
	, Reach(200.f)
	, TestUni(nullptr)
	, AttCheck(false)
	, AttTimeMax(0.8f)
	, AttTime(0.f)
	, ListLastCheck(false)
	, AttCount(0)
	, AttCountMax(3)
{
}

SunkenC::~SunkenC()
{
}


void SunkenC::AttEnd(const FrameAnimation_DESC& _Info)
{
	AttCheck = true;
	Renderer->ChangeFrameAnimation("sunkenStand");
}

void SunkenC::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 128.f,128.f,1.f });


		Renderer->CreateFrameAnimationFolder("sunkenStand", FrameAnimation_DESC("sunkenStand", 0.1f));
		Renderer->CreateFrameAnimationFolder("sunkenAtt", FrameAnimation_DESC("sunkenAtt", 0.1f,false));

		Renderer->ChangeFrameAnimation("sunkenStand");

		Renderer->AnimationBindEnd("sunkenAtt", &SunkenC::AttEnd, this);

	}

	{
		BiconRenderer = CreateComponent<GameEngineTextureRenderer>();
		BiconRenderer->SetTexture("beacon.png");
		BiconRenderer->ScaleToTexture();
		float4 RenderWorldPos = BiconRenderer->GetTransform().GetWorldPosition();
		BiconRenderer->GetTransform().SetWorldPosition({ RenderWorldPos.x - 5.f, RenderWorldPos.y - 5.f , 1.f });
	}


}

void SunkenC::Update(float _DeltaTime)
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
			++AttCount;
			Renderer->ChangeFrameAnimation("sunkenAtt");

			if (AttCheck)
			{
				TestUni = GetLevel()->CreateActor<Sunken>(OBJECTORDER::Bullet);
				TestUni->GetTransform().SetWorldPosition(TarGetPos);
				TestUni->m_Info.Dammage = 40;
			}
			//BloodBullet
			//Spore
			if (AttCountMax >= (Monsize - 1))
			{
				AttCountMax = (Monsize - 1);
			}

			if (AttCount >= AttCountMax)
			{
				AttCheck = false;
				AttCount = 0;
				break;
			}


		}


		if (MonCount == Monsize)
		{
			Renderer->ChangeFrameAnimation("sunkenStand");
			AttTime = 0.f;
			AttCountMax = 3;
			AttCount = 0;
			AttCheck = false;
		}


	}



	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });

	//Spore
}

