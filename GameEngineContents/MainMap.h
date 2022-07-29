
#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :
class GameEngineTextureRenderer;
class MainMap : public GameEngineActor
{
public:
	// constrcuter destructer
	MainMap();
	~MainMap();

	// delete Function
	MainMap(const MainMap& _Other) = delete;
	MainMap(MainMap&& _Other) noexcept = delete;
	MainMap& operator=(const MainMap& _Other) = delete;
	MainMap& operator=(MainMap&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	GameEngineTextureRenderer* Renderer;



private:

};
