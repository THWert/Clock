#pragma once
class MainGame : public Scene
{
private:
	ObCircle cc;
	ObLine hour;
	ObLine min;
	ObLine sec;

	SYSTEMTIME localTime;
public:
	~MainGame() override;
	//æ¿ √ ±‚»≠
	virtual void Init() override;
	//æ¿ ∞ªΩ≈
	virtual void Update() override;
	//æ¿ √‚∑¬
	virtual void Render() override;
};

