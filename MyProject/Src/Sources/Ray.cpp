#include "Ray.h"

Ray::Ray()
{
}

Ray::~Ray()
{
}

void Ray::Update(glm::vec3 origin, glm::vec3 end, glm::mat4 projection, glm::mat4 view)
{
	glm::vec3 ray_ndc = end;

	glm::vec4 ray_clip = glm::vec4(ray_ndc, 1.0f);

	glm::vec4 ray_eye = inverse(projection) * ray_clip;

	glm::vec4 ray_world = inverse(view) * ray_eye;

	if (ray_world.w != 0.0)
	{
		ray_world.x /= ray_world.w;
		ray_world.y /= ray_world.w;
		ray_world.z /= ray_world.w;
	}

	glm::vec3 ray_dir = normalize(glm::vec3(ray_world) - origin);

	this->ray = ray_dir;
}

bool Ray::Intersect(glm::vec3& origin,  GameObject& aabb)
{
    glm::vec3 ptOnPlane; //�������Χ��ĳ��Ľ���
    glm::vec3 min = glm::vec3(aabb.Position.x - aabb.Size.x / 2, aabb.Position.y - aabb.Size.y / 2, aabb.Position.z - aabb.Size.z / 2); //aabb��Χ����С������
    glm::vec3 max = glm::vec3(aabb.Position.x + aabb.Size.x / 2, aabb.Position.y + aabb.Size.y / 2, aabb.Position.z + aabb.Size.z / 2); //aabb��Χ����������

    const glm::vec3& dir = this->ray; //����ʸ��

    float t;

    //�ֱ��ж������������ཻ���

    //�ж��������Χ��x�᷽������Ƿ��н���
    if (dir.x != 0.f) //����x�᷽�������Ϊ0 �����߷���ʸ����x�����Ϊ0�����߲����ܾ�����Χ�г�x�᷽���������
    {
        /*
          ʹ��������ƽ���ཻ�Ĺ�ʽ�󽻵�
         */
        if (dir.x > 0)//��������x��������ƫ��
            t = (min.x - origin.x) / dir.x;
        else  //������x�Ḻ����ƫ��
            t = (max.x - origin.x) / dir.x;

        if (t > 0.f && t < 3.0f) //t>0ʱ��������ƽ���ཻ
        {
            ptOnPlane = origin + t * dir; //���㽻������
            //�жϽ����Ƿ��ڵ�ǰ����
            if (min.y < ptOnPlane.y && ptOnPlane.y < max.y && min.z < ptOnPlane.z && ptOnPlane.z < max.z)
            {
                return true; //�������Χ���н���
            }
        }
    }

    //��������y�᷽���з��� �ж��Ƿ����Χ��y�᷽���н���
    if (dir.y != 0.f)
    {
        if (dir.y > 0)
            t = (min.y - origin.y) / dir.y;
        else
            t = (max.y - origin.y) / dir.y;

        if (t > 0.f && t < 3.0f)
        {
            ptOnPlane = origin + t * dir;

            if (min.z < ptOnPlane.z && ptOnPlane.z < max.z && min.x < ptOnPlane.x && ptOnPlane.x < max.x)
            {
                return true;
            }
        }
    }

    //��������z�᷽���з��� �ж��Ƿ����Χ��y�᷽���н���
    if (dir.z != 0.f)
    {
        if (dir.z > 0)
            t = (min.z - origin.z) / dir.z;
        else
            t = (max.z - origin.z) / dir.z;

        if (t > 0.f && t < 3.0f)
        {
            ptOnPlane = origin + t * dir;

            if (min.x < ptOnPlane.x && ptOnPlane.x < max.x && min.y < ptOnPlane.y && ptOnPlane.y < max.y)
            {
                return true;
            }
        }
    }

    return false;
}