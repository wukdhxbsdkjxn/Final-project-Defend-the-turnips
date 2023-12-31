/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#include "LoginScene.h"
#include "AppDelegate.h"
#include "FlyScene.h"

// #define USE_AUDIO_ENGINE 1
// #define USE_SIMPLE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE && USE_SIMPLE_AUDIO_ENGINE
#error "Don't use AudioEngine and SimpleAudioEngine at the same time. Please just select one in your game!"
#endif

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#elif USE_SIMPLE_AUDIO_ENGINE
#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;
#endif

USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(1024, 576);
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);
//����
AppDelegate::AppDelegate()
{
}
//����
AppDelegate::~AppDelegate() 
{
#if USE_AUDIO_ENGINE
    AudioEngine::end();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::end();
#endif
}
//�����Ҫ��ͬ�������ģ����޸�glContextAttrs��ֵ
//����Ӱ������ƽ̨
// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    //����OpenGL����������:��ɫ����ɫ����ɫ��alpha����ȡ�ģ�ߡ����ز�������
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil,multisamplesCount
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8, 0};

    GLView::setGLContextAttrs(glContextAttrs);
}
//�������ʹ���������������װ������������
//���޸Ļ�ɾ���˺�����һ�㲻��Ҫ�޸�
// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}
/**
    @brief�ڴ˴�ʵ��Director�ͳ�����ʼ�����롣
    @return true��ʼ���ɹ���Ӧ�ó��������
    @return false��ʼ��ʧ�ܣ�Ӧ����ֹ��
    */
bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    //��ʼ������
    auto director = Director::getInstance();
    // ��ȡOpenGL��ͼ
    auto glview = director->getOpenGLView();
    if(!glview) {// ���OpenGL��ͼ������
        // ��Windows��Mac��Linuxƽ̨�ϣ�ʹ��ָ����С�ľ��δ���OpenGL��ͼ
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("PROJECT-NAME", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
        // ������ƽ̨�ϣ�ʹ��Ĭ�ϴ�С����OpenGL��ͼ
        glview = GLViewImpl::create("PROJECT-NAME");
#endif
        // ����OpenGL��ͼ
        director->setOpenGLView(glview);
    }
    // ��ʾFPS��֡�ʣ���Ϣ
    // turn on display FPS
    director->setDisplayStats(true);
    // ����֡�ʣ�������޸����������Ĭ��ֵ��1.0/60
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 60);
    // ������Ʒֱ��ʴ�С
    // Set the design resolution
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
   // ��ȡ��ǰ��ͼ��֡��frame����С
    auto frameSize = glview->getFrameSize();
    // �����ͼ�ĸ߶ȴ���mediumResolutionSize�ĸ߶�
    // if the frame's height is larger than the height of medium size.
    if (frameSize.height > mediumResolutionSize.height)
    {        
        // ���������������ӣ�ȷ����ӦlargeResolutionSize
        director->setContentScaleFactor(MIN(largeResolutionSize.height/designResolutionSize.height, largeResolutionSize.width/designResolutionSize.width));
    }
    // �����ͼ�ĸ߶ȴ���smallResolutionSize�ĸ߶�
    else if (frameSize.height > smallResolutionSize.height)
    {       
        // ���������������ӣ�ȷ����ӦmediumResolutionSize
        director->setContentScaleFactor(MIN(mediumResolutionSize.height/designResolutionSize.height, mediumResolutionSize.width/designResolutionSize.width));
    }
    // �����ͼ�ĸ߶�С��mediumResolutionSize�ĸ߶�
    else
    {        
        // ���������������ӣ�ȷ����ӦsmallResolutionSize
        director->setContentScaleFactor(MIN(smallResolutionSize.height/designResolutionSize.height, smallResolutionSize.width/designResolutionSize.width));
    }
    // ע��������չ��
    register_all_packages();
    // ����һ����������һ���Զ��ͷŵĶ���
    auto scene = LoginScene::createLoginScene();
    // ���г���
    director->runWithScene(scene);
    // ����true��ʾӦ�ó��������ɹ�
    return true;
}
/**
    @brief��Ӧ�ó����Ƶ���̨ʱ����
    @paramӦ�ó����ָ��
    ����Ӧ�ó�������̨ʱ���õĻص�����������Ϸ�����У�
    ������л�������Ӧ�û�������Ļʱ��Ӧ�ó��������̨״̬��
    ��������ṩ��һ��������ִ��һЩ��Ӧ�ó�������̨ʱ��Ҫ���еĲ�����
    */
// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();//ֹͣ��Ϸѭ������������Ϊ�˼�����Դռ�ã���Ϊ�ں�̨ʱ��Ϸ������Ҫ����ʵʱ��Ⱦ��
    /*#if USE_AUDIO_ENGINE �� #elif USE_SIMPLE_AUDIO_ENGINE:
    �ⲿ�ִ������Ԥ����ĺ� USE_AUDIO_ENGINE �� USE_SIMPLE_AUDIO_ENGINE ��ѡ���Ե���ͣ��Ƶ���档
    ����Ϊ��ȷ���ں�̨ʱ��Ƶ������������������������ѡ��ͬ����Ƶ����ʵ�ֵģ�
    ���Ը�����Ŀ����Ҫѡ������֮һ��

���ʹ�� USE_AUDIO_ENGINE������� AudioEngine::pauseAll() ��ͣ������Ƶ��
���ʹ�� USE_SIMPLE_AUDIO_ENGINE����ʹ�� SimpleAudioEngine ��ͣ�������ֺ�������Ч��*/
#if USE_AUDIO_ENGINE
    AudioEngine::pauseAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    SimpleAudioEngine::getInstance()->pauseAllEffects();
#endif
}
/*��Ӧ�ó��򼴽��Ӻ�̨����ǰ̨ʱ���õĻص�����������Ϸ�����У�
����Ҵ�����Ӧ���л���Ϸʱ��Ӧ�ó����Ӻ�̨�л���ǰ̨��
��������ṩ��һ��������ִ��һЩ��Ӧ�ó������ǰ̨ʱ��Ҫ���еĲ�����*/
// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();//����������Ϸѭ����������Ӧ�ó������ǰ̨ʱ����Ҫ���¿�ʼ��Ϸѭ���Խ���ʵʱ��Ⱦ��
    /*�ⲿ�ִ������Ԥ����ĺ� USE_AUDIO_ENGINE �� USE_SIMPLE_AUDIO_ENGINE ��ѡ���Եػָ���Ƶ���档
    ����Ϊ��ȷ����ǰ̨ʱ��Ƶ�����������š�

���ʹ�� USE_AUDIO_ENGINE������� AudioEngine::resumeAll() �ָ�������Ƶ��
���ʹ�� USE_SIMPLE_AUDIO_ENGINE����ʹ�� SimpleAudioEngine �ָ��������ֺ�������Ч��*/
#if USE_AUDIO_ENGINE
    AudioEngine::resumeAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
#endif
}
