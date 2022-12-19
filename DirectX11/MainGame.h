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
	//�� �ʱ�ȭ
	virtual void Init() override;
	//�� ����
	virtual void Update() override;
	//�� ���
	virtual void Render() override;
};

