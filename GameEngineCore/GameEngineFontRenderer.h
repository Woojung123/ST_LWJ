#pragma once
#include "GameEngineFont.h"
#include "GameEngineDefaultRenderer.h"
#include "GameEngineRenderTarget.h"

// ???? :
class GameEngineDevice;
class GameEngineFontRenderer : public GameEngineDefaultRenderer
{
	friend GameEngineDevice;
	static GameEngineRenderTarget* FontTarget;

public:
	// constrcuter destructer
	GameEngineFontRenderer();
	~GameEngineFontRenderer();

	// delete Functionq
	GameEngineFontRenderer(const GameEngineFontRenderer& _Other) = delete;
	GameEngineFontRenderer(GameEngineFontRenderer&& _Other) noexcept = delete;
	GameEngineFontRenderer& operator=(const GameEngineFontRenderer& _Other) = delete;
	GameEngineFontRenderer& operator=(GameEngineFontRenderer&& _Other) noexcept = delete;

	void SetText(const std::string& _Text, const std::string& _Font = "????");

	std::string GetText() 
	{
		return Text;
	}

protected:
	virtual void Start();

	virtual void Render(float _DeltaTime);

private:
	std::string Text;
	GameEngineFont* Font;
	float FontSize;
	float4 Color;
	float4 ScreenPostion;
};

