#include "pipeline.h"


const Matrix4f* Pipeline::GetTrans() //ãåíåðàöèÿ èòîãîâîé ìàòðèöû ïðåîáðàçîâàíèÿ îáúåêòîâ
{
    Matrix4f ScaleTrans, RotateTrans, TranslationTrans, CameraTranslationTrans, CameraRotateTrans, PersProjTrans;

    ScaleTrans.InitScaleTransform(m_scale.x, m_scale.y, m_scale.z);
    RotateTrans.InitRotateTransform(m_rotateInfo.x, m_rotateInfo.y, m_rotateInfo.z);
    TranslationTrans.InitTranslationTransform(m_worldPos.x, m_worldPos.y, m_worldPos.z);
    //Ïðåîáðàçîâàíèå êàìåðû: ñìåùåíèå íà îáðàòíûé âåêòîð ïîçèöèè
    CameraTranslationTrans.InitTranslationTransform(-m_camera.Pos.x, -m_camera.Pos.y, -m_camera.Pos.z);
    //Âðàùåíèå êàìåðû
    CameraRotateTrans.InitCameraTransform(m_camera.Target, m_camera.Up);
    PersProjTrans.InitPersProjTransform(m_persProj.FOV, m_persProj.Width, m_persProj.Height, m_persProj.zNear, m_persProj.zFar);
    //Ñòàâèì ìàòðèöó ïåðñïåêòèâû ïåðâîé, ò.ê. âåêòîð ïîçèöèè óìíîæàåòñÿ ñ ïðàâîé ñòîðîíû îò èòîãîâîé ìàòðèöû
    m_transformation = PersProjTrans * CameraRotateTrans * CameraTranslationTrans * TranslationTrans * RotateTrans * ScaleTrans;
    return &m_transformation;
}