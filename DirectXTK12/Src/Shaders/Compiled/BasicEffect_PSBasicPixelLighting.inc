#if 0
//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// TEXCOORD                 0   xyzw        0     NONE   float   xyzw
// TEXCOORD                 1   xyz         1     NONE   float   xyz 
// COLOR                    0   xyzw        2     NONE   float   xyzw
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Target                0   xyzw        0   TARGET   float   xyzw
//
ps_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer CB0[14], immediateIndexed
dcl_input_ps linear v0.xyzw
dcl_input_ps linear v1.xyz
dcl_input_ps linear v2.xyzw
dcl_output o0.xyzw
dcl_temps 4
add r0.xyz, -v0.xyzx, cb0[12].xyzx
dp3 r0.w, r0.xyzx, r0.xyzx
rsq r0.w, r0.w
mad r1.xyz, r0.xyzx, r0.wwww, -cb0[3].xyzx
dp3 r1.w, r1.xyzx, r1.xyzx
rsq r1.w, r1.w
mul r1.xyz, r1.wwww, r1.xyzx
dp3 r1.w, v1.xyzx, v1.xyzx
rsq r1.w, r1.w
mul r2.xyz, r1.wwww, v1.xyzx
dp3 r1.x, r1.xyzx, r2.xyzx
mad r3.xyz, r0.xyzx, r0.wwww, -cb0[4].xyzx
mad r0.xyz, r0.xyzx, r0.wwww, -cb0[5].xyzx
dp3 r0.w, r3.xyzx, r3.xyzx
rsq r0.w, r0.w
mul r3.xyz, r0.wwww, r3.xyzx
dp3 r1.y, r3.xyzx, r2.xyzx
dp3 r0.w, r0.xyzx, r0.xyzx
rsq r0.w, r0.w
mul r0.xyz, r0.wwww, r0.xyzx
dp3 r1.z, r0.xyzx, r2.xyzx
max r0.xyz, r1.xyzx, l(0.000000, 0.000000, 0.000000, 0.000000)
dp3 r1.x, -cb0[3].xyzx, r2.xyzx
dp3 r1.y, -cb0[4].xyzx, r2.xyzx
dp3 r1.z, -cb0[5].xyzx, r2.xyzx
ge r2.xyz, r1.xyzx, l(0.000000, 0.000000, 0.000000, 0.000000)
and r2.xyz, r2.xyzx, l(0x3f800000, 0x3f800000, 0x3f800000, 0)
mul r0.xyz, r0.xyzx, r2.xyzx
mul r1.xyz, r1.xyzx, r2.xyzx
log r0.xyz, r0.xyzx
mul r0.xyz, r0.xyzx, cb0[2].wwww
exp r0.xyz, r0.xyzx
mul r2.xyz, r0.yyyy, cb0[10].xyzx
mad r0.xyw, r0.xxxx, cb0[9].xyxz, r2.xyxz
mad r0.xyz, r0.zzzz, cb0[11].xyzx, r0.xywx
mul r0.xyz, r0.xyzx, cb0[2].xyzx
mul r0.xyz, r0.xyzx, v2.wwww
mul r2.xyz, r1.yyyy, cb0[7].xyzx
mad r1.xyw, r1.xxxx, cb0[6].xyxz, r2.xyxz
mad r1.xyz, r1.zzzz, cb0[8].xyzx, r1.xywx
mad r1.xyz, r1.xyzx, cb0[0].xyzx, cb0[1].xyzx
mad r0.xyz, v2.xyzx, r1.xyzx, r0.xyzx
mad r1.xyz, cb0[13].xyzx, v2.wwww, -r0.xyzx
mad o0.xyz, v0.wwww, r1.xyzx, r0.xyzx
mov o0.w, v2.w
ret 
// Approximately 0 instruction slots used
#endif

const BYTE BasicEffect_PSBasicPixelLighting[] =
{
     68,  88,  66,  67,  86, 192, 
    121, 125, 135,  91,   3, 110, 
    182, 132, 176,  60,  86,  33, 
     16,  76,   1,   0,   0,   0, 
     64,   7,   0,   0,   4,   0, 
      0,   0,  48,   0,   0,   0, 
    152,   0,   0,   0, 204,   0, 
      0,   0, 188,   6,   0,   0, 
     73,  83,  71,  78,  96,   0, 
      0,   0,   3,   0,   0,   0, 
      8,   0,   0,   0,  80,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,  15,   0,   0,  80,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
      7,   7,   0,   0,  89,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
     15,  15,   0,   0,  84,  69, 
     88,  67,  79,  79,  82,  68, 
      0,  67,  79,  76,  79,  82, 
      0, 171,  79,  83,  71,  78, 
     44,   0,   0,   0,   1,   0, 
      0,   0,   8,   0,   0,   0, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
     83,  86,  95,  84,  97, 114, 
    103, 101, 116,   0, 171, 171, 
     83,  72,  69,  88, 232,   5, 
      0,   0,  80,   0,   0,   0, 
    122,   1,   0,   0, 106,   8, 
      0,   1,  89,   0,   0,   4, 
     70, 142,  32,   0,   0,   0, 
      0,   0,  14,   0,   0,   0, 
     98,  16,   0,   3, 242,  16, 
     16,   0,   0,   0,   0,   0, 
     98,  16,   0,   3, 114,  16, 
     16,   0,   1,   0,   0,   0, 
     98,  16,   0,   3, 242,  16, 
     16,   0,   2,   0,   0,   0, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   0,   0,   0,   0, 
    104,   0,   0,   2,   4,   0, 
      0,   0,   0,   0,   0,   9, 
    114,   0,  16,   0,   0,   0, 
      0,   0,  70,  18,  16, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,  70, 130,  32,   0, 
      0,   0,   0,   0,  12,   0, 
      0,   0,  16,   0,   0,   7, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     68,   0,   0,   5, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  50,   0,   0,  11, 
    114,   0,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0, 246,  15, 
     16,   0,   0,   0,   0,   0, 
     70, 130,  32, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,  16,   0, 
      0,   7, 130,   0,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  68,   0,   0,   5, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,  56,   0, 
      0,   7, 114,   0,  16,   0, 
      1,   0,   0,   0, 246,  15, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  16,   0,   0,   7, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  70,  18,  16,   0, 
      1,   0,   0,   0,  70,  18, 
     16,   0,   1,   0,   0,   0, 
     68,   0,   0,   5, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,   7, 
    114,   0,  16,   0,   2,   0, 
      0,   0, 246,  15,  16,   0, 
      1,   0,   0,   0,  70,  18, 
     16,   0,   1,   0,   0,   0, 
     16,   0,   0,   7,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,  50,   0, 
      0,  11, 114,   0,  16,   0, 
      3,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
    246,  15,  16,   0,   0,   0, 
      0,   0,  70, 130,  32, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
     50,   0,   0,  11, 114,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0, 246,  15,  16,   0, 
      0,   0,   0,   0,  70, 130, 
     32, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   5,   0, 
      0,   0,  16,   0,   0,   7, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      3,   0,   0,   0,  70,   2, 
     16,   0,   3,   0,   0,   0, 
     68,   0,   0,   5, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   7, 
    114,   0,  16,   0,   3,   0, 
      0,   0, 246,  15,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   3,   0,   0,   0, 
     16,   0,   0,   7,  34,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   3,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,  16,   0, 
      0,   7, 130,   0,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  68,   0,   0,   5, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   7, 114,   0,  16,   0, 
      0,   0,   0,   0, 246,  15, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  16,   0,   0,   7, 
     66,   0,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   2,   0,   0,   0, 
     52,   0,   0,  10, 114,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  16,   0, 
      0,   9,  18,   0,  16,   0, 
      1,   0,   0,   0,  70, 130, 
     32, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,  16,   0, 
      0,   9,  34,   0,  16,   0, 
      1,   0,   0,   0,  70, 130, 
     32, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,  16,   0, 
      0,   9,  66,   0,  16,   0, 
      1,   0,   0,   0,  70, 130, 
     32, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   5,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,  29,   0, 
      0,  10, 114,   0,  16,   0, 
      2,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,  10, 
    114,   0,  16,   0,   2,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128,  63, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0,   0,   0, 
     56,   0,   0,   7, 114,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,  56,   0, 
      0,   7, 114,   0,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,  47,   0,   0,   5, 
    114,   0,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   8, 114,   0,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
    246, 143,  32,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
     25,   0,   0,   5, 114,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   8, 
    114,   0,  16,   0,   2,   0, 
      0,   0,  86,   5,  16,   0, 
      0,   0,   0,   0,  70, 130, 
     32,   0,   0,   0,   0,   0, 
     10,   0,   0,   0,  50,   0, 
      0,  10, 178,   0,  16,   0, 
      0,   0,   0,   0,   6,   0, 
     16,   0,   0,   0,   0,   0, 
     70, 136,  32,   0,   0,   0, 
      0,   0,   9,   0,   0,   0, 
     70,   8,  16,   0,   2,   0, 
      0,   0,  50,   0,   0,  10, 
    114,   0,  16,   0,   0,   0, 
      0,   0, 166,  10,  16,   0, 
      0,   0,   0,   0,  70, 130, 
     32,   0,   0,   0,   0,   0, 
     11,   0,   0,   0,  70,   3, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   8, 114,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  70, 130,  32,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,  56,   0,   0,   7, 
    114,   0,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0, 246,  31, 
     16,   0,   2,   0,   0,   0, 
     56,   0,   0,   8, 114,   0, 
     16,   0,   2,   0,   0,   0, 
     86,   5,  16,   0,   1,   0, 
      0,   0,  70, 130,  32,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,  50,   0,   0,  10, 
    178,   0,  16,   0,   1,   0, 
      0,   0,   6,   0,  16,   0, 
      1,   0,   0,   0,  70, 136, 
     32,   0,   0,   0,   0,   0, 
      6,   0,   0,   0,  70,   8, 
     16,   0,   2,   0,   0,   0, 
     50,   0,   0,  10, 114,   0, 
     16,   0,   1,   0,   0,   0, 
    166,  10,  16,   0,   1,   0, 
      0,   0,  70, 130,  32,   0, 
      0,   0,   0,   0,   8,   0, 
      0,   0,  70,   3,  16,   0, 
      1,   0,   0,   0,  50,   0, 
      0,  11, 114,   0,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     70, 130,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     70, 130,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     50,   0,   0,   9, 114,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  18,  16,   0,   2,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     50,   0,   0,  11, 114,   0, 
     16,   0,   1,   0,   0,   0, 
     70, 130,  32,   0,   0,   0, 
      0,   0,  13,   0,   0,   0, 
    246,  31,  16,   0,   2,   0, 
      0,   0,  70,   2,  16, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,  50,   0,   0,   9, 
    114,  32,  16,   0,   0,   0, 
      0,   0, 246,  31,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  54,   0,   0,   5, 
    130,  32,  16,   0,   0,   0, 
      0,   0,  58,  16,  16,   0, 
      2,   0,   0,   0,  62,   0, 
      0,   1,  82,  84,  83,  48, 
    124,   0,   0,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
     24,   0,   0,   0,   0,   0, 
      0,   0, 124,   0,   0,   0, 
     29,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     60,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     88,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
    116,   0,   0,   0,   1,   0, 
      0,   0,  68,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   1,   0,   0,   0, 
     96,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,   0,   0, 
      0,   0
};