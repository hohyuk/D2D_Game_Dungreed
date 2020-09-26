#pragma once

#define FPS_MGR			FPS_Manager::Get_Instance()
#define TIME_MGR		TimeManager::Get_Instance()
#define DELTA_TIME		TIME_MGR->Get_DeltaTime()

#define GD_MGR			GraphicDevice::Get_Instance()
#define TEXTURE_MGR		TextureManager::Get_Instance()

#define SCENE_MGR		SceneManager::Get_Instance()
#define OBJ_MGR			GameObjectManager::Get_Instance()
#define MOUSE_POINT		OBJ_MGR->Get_MousePoint()

#define KEY_MGR			KeyManager::Get_Instance()

#define SOUND_MGR		SoundManager::Get_Instance()
#define SOUND_ID		SoundManager::CHANNELID