

#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :
class GameEngineTextureRenderer;
class SingleButton : public GameEngineActor
{
public:
	// constrcuter destructer
	SingleButton();
	~SingleButton();

	// delete Function
	SingleButton(const SingleButton& _Other) = delete;
	SingleButton(SingleButton&& _Other) noexcept = delete;
	SingleButton& operator=(const SingleButton& _Other) = delete;
	SingleButton& operator=(SingleButton&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	GameEngineTextureRenderer* Renderer;



private:

};
