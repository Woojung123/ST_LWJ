

#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class mutalBullet;
class GameEngineTextureRenderer;
class MutalA : public UnitBase
{
public:
	// constrcuter destructer
	MutalA();
	~MutalA();

	// delete Function
	MutalA(const MutalA& _Other) = delete;
	MutalA(MutalA&& _Other) noexcept = delete;
	MutalA& operator=(const MutalA& _Other) = delete;
	MutalA& operator=(MutalA&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}
	void AttEnd(const FrameAnimation_DESC& _Info);

	void ChangeAni(float4 _Gopoint, float4 _WorldPos);
	GameEngineTextureRenderer* Renderer;

	GameEngineTextureRenderer* BiconRenderer;
	GameEngineTextureRenderer* AuraRenderer;
	mutalBullet* TestUni;
	float4 Color;
	float Reach;
public:
	float	Speed;
	float	AttTime;
	float	AttTimeMax;
	float4	m_Dir;

	bool	BAniChange;
	bool	AttCheck;
	bool	ListLastCheck;




	int		AttCount;
	int		AttCountMax;




};

