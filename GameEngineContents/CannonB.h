

#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class DraBall;
class GameEngineTextureRenderer;
class CannonB : public UnitBase
{
public:
	// constrcuter destructer
	CannonB();
	~CannonB();

	// delete Function
	CannonB(const CannonB& _Other) = delete;
	CannonB(CannonB&& _Other) noexcept = delete;
	CannonB& operator=(const CannonB& _Other) = delete;
	CannonB& operator=(CannonB&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}


	void AttEnd(const FrameAnimation_DESC& _Info);
	GameEngineTextureRenderer* BiconRenderer;
	GameEngineTextureRenderer* Renderer;
	DraBall* TestUni;


	int		AttCount;
	int		AttCountMax;
	float4 Color;
	float Reach;
public:
	float	Speed;
	float	AttTime;
	float	AttTimeMax;

	bool	AttCheck;
	bool	ListLastCheck;
};

