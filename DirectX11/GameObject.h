#pragma once
class GameObject
{
public:
	/*Vector3 a;
	Vector4 b;*/

	Vector2 position; //����
	Vector2 scale; //ũ�Ⱚ
	float rotation; //ȸ����

	Matrix S, R, T, W;

public:
	GameObject();
	virtual ~GameObject();

	//�����Լ�
	//�ڽ��� ������ �� ���̶�� ����� �� ���
	virtual void Update();
	virtual void Render();
};

