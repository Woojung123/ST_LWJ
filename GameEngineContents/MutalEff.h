

#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class MutalEff : public UnitBase
{
public:
	// constrcuter destructer
	MutalEff();
	~MutalEff();

	// delete Function
	MutalEff(const MutalEff& _Other) = delete;
	MutalEff(MutalEff&& _Other) noexcept = delete;
	MutalEff& operator=(const MutalEff& _Other) = delete;
	MutalEff& operator=(MutalEff&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}
	void AttEnd(const FrameAnimation_DESC& _Info);
	bool	BAniChange;

	GameEngineTextureRenderer* Renderer;

	float4 Color;

private:
	float Speed;
	float4 m_Dir;

};
