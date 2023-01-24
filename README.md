MyProject
===========================
#### ��������
- Visual studio 2022
- C++14
***
#### ��������
##### OpenGL��
- ��Ⱦ����: OpenGL��ѧ��: glm
- ���ڹ���: OpenGL���ڿ�: GLFW
- ��������: OpenGL������: glad
##### stb��
- ͼƬ��ȡ,д��
##### freetype��
- �ı���Ⱦ
##### irrKlang��
- ��Ϸ��Ƶ
##### Assimp��
- ģ�͵���
***
#### ������
>���岽��ͼƬ����뿴Docs�ļ�����Pics/SetUp�ļ���֮�е�ͼƬ
1. ˫����***Solution.sln***
2. �Ҳ�***���������Դ��������***,�ҵ�***MyProject��Ŀ***,*�Ҽ�*��***����ҳ***
>ǧ��!!!ǧ��!!!!ǧ��!!!!!  
>Ҫע�ⶥ�������ú�ƽ̨ѡ��!!!!!  
>һ��Ҫѡ���������ú�����ƽ̨!!!!!  

3. ������ҳ���***����***,����***���Ŀ¼***��***�м�Ŀ¼*** 
>���Ŀ¼: $(ProjectDir)Temp\Link\$(Platform)\$(Configuration)\  
>�м�Ŀ¼: $(ProjectDir)Temp\Compile\$(Platform)\$(Configuration)\

4. ���***����***,����***����Ŀ¼***
>����Ŀ¼: $(ProjectDir)Bin\$(Platform)\$(Configuration)\  

5. ���***VC++Ŀ¼***,����***����Ŀ¼***��***��Ŀ¼*** 
>����Ŀ¼: $(ProjectDir)Include;$(IncludePath)  
>��Ŀ¼: $(ProjectDir)Lib;$(LibraryPath)

6. ���***C/C++***,����***���Ӱ���Ŀ¼***
>���Ӱ���Ŀ¼: $(ProjectDir)Src\Headers;%(AdditionalIncludeDirectories)  

7. ���*������*�µ�***����***,����***����������***
>����������: һ��Ҫ��Lib�ļ����µ������ļ����Ƽӽ�ȥ  
>��:  
>opengl32.lib  
>glfw3.lib  
>assimp-vc140-mt.lib  
>freetype.lib  
>irrKlang.lib

8. ���***�����¼�***�µ�***���ɺ��¼�***,����***������*** 
>������: xcopy $(TargetPath) $(ProjectDir)Bin\$(Platform)\$(ConfigurationName)\ /y  
>xcopy $(ProjectDir)Resource $(ProjectDir)Bin\$(Platform)\$(ConfigurationName)\Resource /e/y

9. ֮����*ȷ��*,�ڶ�����ѡ����,ѡ��**Release����Debugģʽ**,***һ��Ҫѡ��x64!!!!***.
10. *�Ҽ�* ***MyProject��Ŀ***,���***��������***,������Bin/x64/Release(����Debug)�ļ������ҵ������ɵ�exe�ļ�,���в鿴�Ƿ�ɹ�
***
#### �����Ų�
1. ���#Includeָ����ʾ"�޷���xxx.h�ļ�",�ǵ�ȥMyProject����ҳ�鿴�Ƿ�Headers��Include�ļ��м������Ŀ¼�͸��Ӱ���Ŀ¼
2. �������ʱ����,��ʾ"�޷���xxx.lib�ļ�",�ǵ�ȥLib�ļ��в鿴xxx.lib�ļ��Ƿ�����
3. �������ʱ����,��ʾ��"�޷��������ⲿ����",�ǵò鿴ÿ���ļ���ͷ��Ԥ����ָ��,��������������ʱ���Ƿ���Ҫ��Ԥ�����
4. �������ʱ����,��ʾ��"�޷��������ⲿ����",�ǵ��ڶ����鿴����ѡ���Ƿ�Ϊx64
5. �������ʱ����,��ʾ"������xxxxxxx", �ǵ�ȥBin�ļ����µ�Release��Debug�ļ����²鿴Resource�ļ����Ƿ����,����ȷ����Ŀ�ļ����µ�Resource�ļ����Ƿ����
6. �������ʱ����,�ǵ�ȥRelease��Debug�ļ����²鿴���õĵ��������dll��̬���ӿ��Ƿ�����
7. ���������ⲻ���������κ�һ������,�뽫Temp/Compile�ļ����µ�x64����Win32�ļ�����Debug����Release�ļ����ڵ�MyProject.log�ļ������ڱ����Ĵ����ͼһ�����͸�����
***
#### Ŀ¼�ṹ
```
.
����MyProject
    ����Bin                        //�������ɵ��ļ�
    ��  ����x64                     //ƽ̨
    ��      ����Debug               //��������
    ��      ��  ����Resource         //��Դ
    ��      ��      ����Fonts
    ��      ��      ����Levels
    ��      ��      ����Models
    ��      ��      ����Shaders
    ��      ��      ����Textures
    ��      ����Release
    ��          ����Resource
    ��              ����Fonts
    ��              ����Levels
    ��              ����Models
    ��              ����Shaders
    ��              ����Textures
    ����Docs                       //�ĵ�
    ��  
    ����Include                    //��������ͷ�ļ�
    ��  ����assimp
    ��  ����dlg
    ��  ����freetype
    ��  ����glad
    ��  ����GLFW
    ��  ����glm
    ��  ����irrKlang
    ��  ����KHR
    ��  ����stb
    ����Lib                        //��������̬��
    ����Resource
    ��  ����Fonts
    ��  ����Levels
    ��  ����Models
    ��  ����Shaders
    ��  ����Textures
    ����Src                        //Դ��
    ��  ����Headers                 //Դ��ͷ�ļ�
    ��  ����Sources                 //Դ��Դ�ļ�
    ����Temp                       //�м��ļ�
        ����Compile                //�����м��ļ�
        ��  ����x64
        ��      ����Debug
        ��      ����Release
        ����Link                   //�����м��ļ�
            ����x64
                ����Debug
                ����Release

```
***
#### ��ǰ�汾����
##### Game��
- ������
- ��Ϸѭ������
- ������Ϸ״̬�Ȳ���
- ������Ⱦ����
##### ResourceManager��
- ������
- ʵ�ִ��ļ���ȡ����
- ֧��shader��ȡ
- ֧��������ͼ��ȡ
- ֧�ֹؿ����ݶ�ȡ
##### Shader��
- ������
- ʵ��shaderProgram
- ֧�ֹؿ���Ⱦ,������Ⱦ,������Ⱦ,�ı���Ⱦ
##### Renderer��
- ������
- ʵ����������Ⱦ
##### Texture��
- ������
- ʵ��2D������ͼ
- ʵ��3D������ͼ
##### Camera��
- ������
- ʵ��3D�ƶ�
##### GameLevel��
- ������
- ʵ�ֹؿ���Ⱦ
##### GameObject��
- ������
- ʵ��������Ⱦ
##### Light��
- ������
- ʵ���ı���Ⱦ
##### TextRenderer��
- ������
- ʵ���ı���Ⱦ
##### PostProcessor��
- ������
- ʵ����Ч��Ⱦ
- ʵ����Ӱ��Ⱦ