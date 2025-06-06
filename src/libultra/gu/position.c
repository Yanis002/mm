#include "ultra64.h"
#include "math.h"

/**
 * guPositionF
 * Creates a rotation/parallel translation modelling matrix (floating point)
 */
void guPositionF(f32 mf[4][4], f32 rot, f32 pitch, f32 yaw, f32 scale, f32 x, f32 y, f32 z) {
    static f32 dtor = M_PIf / 180.0f;
    f32 sinr;
    f32 sinp;
    f32 sinh;
    f32 cosr;
    f32 cosp;
    f32 cosh;

    rot *= dtor;
    pitch *= dtor;
    yaw *= dtor;

    sinr = sinf(rot);
    cosr = cosf(rot);
    sinp = sinf(pitch);
    cosp = cosf(pitch);
    sinh = sinf(yaw);
    cosh = cosf(yaw);

    mf[0][0] = (cosp * cosh) * scale;
    mf[0][1] = (cosp * sinh) * scale;
    mf[0][2] = (-sinp) * scale;
    mf[0][3] = 0.0f;

    mf[1][0] = ((sinr * sinp * cosh) - (cosr * sinh)) * scale;
    mf[1][1] = ((sinr * sinp * sinh) + (cosr * cosh)) * scale;
    mf[1][2] = (sinr * cosp) * scale;
    mf[1][3] = 0.0f;

    mf[2][0] = ((cosr * sinp * cosh) + (sinr * sinh)) * scale;
    mf[2][1] = ((cosr * sinp * sinh) - (sinr * cosh)) * scale;
    mf[2][2] = (cosr * cosp) * scale;
    mf[2][3] = 0.0f;

    mf[3][0] = x;
    mf[3][1] = y;
    mf[3][2] = z;
    mf[3][3] = 1.0f;
}

/**
 * guPosition
 * Creates a rotational/parallel translation modeling matrix (fixed point)
 */
void guPosition(Mtx* m, f32 rot, f32 pitch, f32 yaw, f32 scale, f32 x, f32 y, f32 z) {
    f32 mf[4][4];

    guPositionF(mf, rot, pitch, yaw, scale, x, y, z);

    guMtxF2L(mf, m);
}
