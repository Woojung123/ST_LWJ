
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class ArconBul;
class GameEngineTextureRenderer;
class Arcon : public UnitBase
{
public:
	// constrcuter destructer
	Arcon();
	~Arcon();

	// delete Function
	Arcon(const Arcon& _Other) = delete;
	Arcon(Arcon&& _Other) noexcept = delete;
	Arcon& operator=(const Arcon& _Other) = delete;
	Arcon& operator=(Arcon&& _Other) noexcept = delete;

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
	GameEngineTextureRenderer* AuraRenderer2;
	GameEngineTextureRenderer* BackRenderer;
	ArconBul* TestUni;
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

