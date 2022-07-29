
#include "PreCompile.h"
#include "TestUnit.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"DraBall.h"

TestUnit::TestUnit()
	: Speed(50.0f)
	, Renderer(nullptr)
	, Reach(150.f)
	, TestUni(nullptr)
	, AttCheck(false)
	, AttTimeMax(0.8f)
	, AttTime(0.f)
	, ListLastCheck(false)
{
}

TestUnit::~TestUnit()
{
}


void TestUnit::AttEnd(const FrameAnimation_DESC& _Info)
{
	AttCheck = true;
	Renderer->ChangeFrameAnimation("DragonStand");
}

void TestUnit::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 96.f,96.f,1.f });
		

		Renderer->CreateFrameAnimationFolder("DragonStand", FrameAnimation_DESC("DragonStand0", 0.1f));
		Renderer->CreateFrameAnimationFolder("DragonAttack15", FrameAnimation_DESC("DragonAttack15", 0.1f));

		Renderer->ChangeFrameAnimation("DragonStand");

		Renderer->AnimationBindEnd("DragonAttack15", &TestUnit::AttEnd, this);

	}
}

void TestUnit::Update(float _DeltaTime)
{
	//Renderer->ChangeFrameAnimation("DragonAttack15");
	std::list<GameEngineActor*> Group = GetLevel()->GetGroup(OBJECTORDER::Monster);

	int Monsize = (int)Group.size();
	int MonCount = 0;

	auto	iter = Group.begin();
	auto	iterEnd = Group.end();

	for (; iter != iterEnd; ++iter)
	{
		GameEngineActor* TarGet = (*iter);
		float4 TarGetPos = TarGet->GetTransform().GetWorldPosition();
		float4 MyPos = GetTransform().GetWorldPosition();
		float4 Dist = MyPos - TarGetPos;
		float MonLen  = Dist.Length();
		
		++MonCount;

		if (MonLen <= Reach)
		{
			Renderer->ChangeFrameAnimation("DragonAttack15");
			
			if (AttCheck)
			{
				AttCheck = false;
			
				TestUni = GetLevel()->CreateActor<DraBall>(OBJECTORDER::Bullet);
				TestUni->GetTransform().SetWorldPosition(MyPos);
				TestUni->SetTarGet(TarGet);
				
				
			

			}
			//BloodBullet
			//Spore

			break;
		
		}
		
		
		if (MonCount == Monsize)
		{
			Renderer->ChangeFrameAnimation("DragonStand");
			AttTime =0.f;
		}


	}

	

	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });


}

