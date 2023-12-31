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
//构造
AppDelegate::AppDelegate()
{
}
//析构
AppDelegate::~AppDelegate() 
{
#if USE_AUDIO_ENGINE
    AudioEngine::end();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::end();
#endif
}
//如果需要不同的上下文，请修改glContextAttrs的值
//它将影响所有平台
// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    //设置OpenGL上下文属性:红色、绿色、蓝色、alpha、深度、模具、多重采样计数
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil,multisamplesCount
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8, 0};

    GLView::setGLContextAttrs(glContextAttrs);
}
//如果你想使用软件包管理器安装更多的软件包，
//不修改或删除此函数，一般不需要修改
// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}
/**
    @brief在此处实现Director和场景初始化代码。
    @return true初始化成功，应用程序继续。
    @return false初始化失败，应用终止。
    */
bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    //初始化导演
    auto director = Director::getInstance();
    // 获取OpenGL视图
    auto glview = director->getOpenGLView();
    if(!glview) {// 如果OpenGL视图不存在
        // 在Windows、Mac、Linux平台上，使用指定大小的矩形创建OpenGL视图
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("PROJECT-NAME", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
        // 在其他平台上，使用默认大小创建OpenGL视图
        glview = GLViewImpl::create("PROJECT-NAME");
#endif
        // 设置OpenGL视图
        director->setOpenGLView(glview);
    }
    // 显示FPS（帧率）信息
    // turn on display FPS
    director->setDisplayStats(true);
    // 设置帧率，如果不修改这个函数，默认值是1.0/60
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 60);
    // 设置设计分辨率大小
    // Set the design resolution
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
   // 获取当前视图的帧（frame）大小
    auto frameSize = glview->getFrameSize();
    // 如果视图的高度大于mediumResolutionSize的高度
    // if the frame's height is larger than the height of medium size.
    if (frameSize.height > mediumResolutionSize.height)
    {        
        // 设置内容缩放因子，确保适应largeResolutionSize
        director->setContentScaleFactor(MIN(largeResolutionSize.height/designResolutionSize.height, largeResolutionSize.width/designResolutionSize.width));
    }
    // 如果视图的高度大于smallResolutionSize的高度
    else if (frameSize.height > smallResolutionSize.height)
    {       
        // 设置内容缩放因子，确保适应mediumResolutionSize
        director->setContentScaleFactor(MIN(mediumResolutionSize.height/designResolutionSize.height, mediumResolutionSize.width/designResolutionSize.width));
    }
    // 如果视图的高度小于mediumResolutionSize的高度
    else
    {        
        // 设置内容缩放因子，确保适应smallResolutionSize
        director->setContentScaleFactor(MIN(smallResolutionSize.height/designResolutionSize.height, smallResolutionSize.width/designResolutionSize.width));
    }
    // 注册所有扩展包
    register_all_packages();
    // 创建一个场景，是一个自动释放的对象
    auto scene = LoginScene::createLoginScene();
    // 运行场景
    director->runWithScene(scene);
    // 返回true表示应用程序启动成功
    return true;
}
/**
    @brief当应用程序移到后台时调用
    @param应用程序的指针
    是在应用程序进入后台时调用的回调函数。在游戏开发中，
    当玩家切换到其他应用或锁定屏幕时，应用程序会进入后台状态。
    这个函数提供了一个机会来执行一些在应用程序进入后台时需要进行的操作。
    */
// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();//停止游戏循环动画。这是为了减少资源占用，因为在后台时游戏不再需要进行实时渲染。
    /*#if USE_AUDIO_ENGINE 和 #elif USE_SIMPLE_AUDIO_ENGINE:
    这部分代码根据预定义的宏 USE_AUDIO_ENGINE 或 USE_SIMPLE_AUDIO_ENGINE 来选择性地暂停音频引擎。
    这是为了确保在后台时音频的正常处理。这两个宏是用于选择不同的音频引擎实现的，
    可以根据项目的需要选择其中之一。

如果使用 USE_AUDIO_ENGINE，则调用 AudioEngine::pauseAll() 暂停所有音频。
如果使用 USE_SIMPLE_AUDIO_ENGINE，则使用 SimpleAudioEngine 暂停背景音乐和所有音效。*/
#if USE_AUDIO_ENGINE
    AudioEngine::pauseAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    SimpleAudioEngine::getInstance()->pauseAllEffects();
#endif
}
/*在应用程序即将从后台进入前台时调用的回调函数。在游戏开发中，
当玩家从其他应用切回游戏时，应用程序会从后台切换到前台。
这个函数提供了一个机会来执行一些在应用程序进入前台时需要进行的操作。*/
// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();//重新启动游戏循环动画。在应用程序进入前台时，需要重新开始游戏循环以进行实时渲染。
    /*这部分代码根据预定义的宏 USE_AUDIO_ENGINE 或 USE_SIMPLE_AUDIO_ENGINE 来选择性地恢复音频引擎。
    这是为了确保在前台时音频可以正常播放。

如果使用 USE_AUDIO_ENGINE，则调用 AudioEngine::resumeAll() 恢复所有音频。
如果使用 USE_SIMPLE_AUDIO_ENGINE，则使用 SimpleAudioEngine 恢复背景音乐和所有音效。*/
#if USE_AUDIO_ENGINE
    AudioEngine::resumeAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
#endif
}
