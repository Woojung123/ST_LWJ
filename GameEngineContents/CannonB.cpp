

#include "PreCompile.h"
#include "CannonB.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"DraBall.h"

CannonB::CannonB()
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
	, AttCountMax(5)
{
}

CannonB::~CannonB()
{
}


void CannonB::AttEnd(const FrameAnimation_DESC& _Info)
{
	AttCheck = true;
	Renderer->ChangeFrameAnimation("CannonStand");
}

void CannonB::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 64.f,128.f,1.f });


		Renderer->CreateFrameAnimationFolder("CannonStand", FrameAnimation_DESC("CannonStand", 0.1f));
		Renderer->CreateFrameAnimationFolder("CannonAtt", FrameAnimation_DESC("CannonAtt", 0.1f));

		Renderer->ChangeFrameAnimation("CannonStand");

		Renderer->AnimationBindEnd("CannonAtt", &CannonB::AttEnd, this);

	}

	{
		BiconRenderer = CreateComponent<GameEngineTextureRenderer>();
		BiconRenderer->SetTexture("beacon.png");
		BiconRenderer->ScaleToTexture();
		float4 RenderWorldPos = BiconRenderer->GetTransform().GetWorldPosition();
		BiconRenderer->GetTransform().SetWorldPosition({ RenderWorldPos.x - 5.f, RenderWorldPos.y - 5.f , 1.f });
	}


}

void CannonB::Update(float _DeltaTime)
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
			Renderer->ChangeFrameAnimation("CannonAtt");
			
			if (AttCheck)
			{
				//AttCheck = false;

				TestUni = GetLevel()->CreateActor<DraBall>(OBJECTORDER::Bullet);
				MyPos.y = MyPos.y + 10.f;
				TestUni->GetTransform().SetWorldPosition(MyPos);
				TestUni->SetTarGet(TarGet);

				


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
			Renderer->ChangeFrameAnimation("CannonStand");
			AttTime = 0.f;
			AttCountMax = 3;
			AttCount = 0;
			AttCheck = false;
		}


	}



	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });


}

