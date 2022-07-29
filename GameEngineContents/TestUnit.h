
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class DraBall;
class GameEngineTextureRenderer;
class TestUnit : public UnitBase
{
public:
	// constrcuter destructer
	TestUnit();
	~TestUnit();

	// delete Function
	TestUnit(const TestUnit& _Other) = delete;
	TestUnit(TestUnit&& _Other) noexcept = delete;
	TestUnit& operator=(const TestUnit& _Other) = delete;
	TestUnit& operator=(TestUnit&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	
	void AttEnd(const FrameAnimation_DESC& _Info);

	GameEngineTextureRenderer* Renderer;
	DraBall* TestUni;

	float4 Color;
	float Reach;
public:
	float	Speed;
	float	AttTime;
	float	AttTimeMax;

	bool	AttCheck;
	bool	ListLastCheck;
};

