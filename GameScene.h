#include "DirectXCommon.h"
#include "input.h"
#include "DirectXTex.h"
#include "Sphere.h"
#include "Cube.h"
#include "object3D.h"
#include "list"
#include "memory"
#include "Texture.h"

class GameScene
{
	//�����o�֐�
public:
	GameScene();
	~GameScene();
	void Initialize(DirectXCommon* dxCommon, Input* input);
	void Update();
	void Draw();

	//�����o�ϐ�
private: 
	//�f�o�C�X��input
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;

	//���̂̃��f��
	XMFLOAT3 size1 = { 1.0f,1.0f,1.0f };
	std::unique_ptr<Sphere> sphere_;

	//�L���[�u�̃��f��
	XMFLOAT3 size2 = { 1.0f,1.0f,1.0f };
	std::unique_ptr<Cube> cube_;

	//�摜
	size_t textureCount_ = 2;	//�e�N�X�`���̐�
	std::vector<Texture> texture_;	//�e�N�X�`��

	//3D�I�u�W�F�N�g
	size_t kObjectCount = 2;		//�I�u�W�F�N�g�̐�
	std::vector<Object3d> object3ds_;	//�I�u�W�F�N�g

	//�ˉe�ϊ�
	XMMATRIX matProjection = XMMatrixPerspectiveFovLH(
		XMConvertToRadians(45.0f),			//�㉺��p45�x
		(float)window_width / window_height,//�A�X�y�N�g��(��ʉ���/��ʗ���)
		0.1f, 1000.0f						//�O�[�A���[
	);

	//�r���[�ϊ��s��
	XMMATRIX matView;
	XMFLOAT3 eye = { 0, 0, -100 };
	XMFLOAT3 target = { 0, 0, 0 };
	XMFLOAT3 up = { 0, 1, 0 };
};
