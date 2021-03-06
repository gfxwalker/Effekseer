#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
//   fxc /Zpc /Tvs_4_0 /EVS /D __EFFEKSEER_BUILD_VERSION16__=1 /Fh
//    Shader/EffekseerRenderer.ModelRenderer.ShaderLightingTextureNormal_VS.h
//    Shader/model_renderer_lighting_texture_normal_VS.fx
//
//
// Buffer Definitions: 
//
// cbuffer VS_ConstantBuffer
// {
//
//   float4x4 mCameraProj;              // Offset:    0 Size:    64
//   float4x4 mModel[40];               // Offset:   64 Size:  2560
//   float4 fUV[40];                    // Offset: 2624 Size:   640
//   float4 fAlphaUV[40];               // Offset: 3264 Size:   640
//   float4 fFlipbookParameter;         // Offset: 3904 Size:    16
//   float4 fFlipbookIndexAndNextRate[40];// Offset: 3920 Size:   640
//   float4 fModelAlphaThreshold[40];   // Offset: 4560 Size:   640
//   float4 fModelColor[40];            // Offset: 5200 Size:   640
//   float4 fLightDirection;            // Offset: 5840 Size:    16 [unused]
//   float4 fLightColor;                // Offset: 5856 Size:    16 [unused]
//   float4 fLightAmbient;              // Offset: 5872 Size:    16 [unused]
//   float4 mUVInversed;                // Offset: 5888 Size:    16
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// VS_ConstantBuffer                 cbuffer      NA          NA    0        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// POSITION                 0   xyz         0     NONE  float   xyz 
// NORMAL                   0   xyz         1     NONE  float   xyz 
// NORMAL                   1   xyz         2     NONE  float   xyz 
// NORMAL                   2   xyz         3     NONE  float   xyz 
// TEXCOORD                 0   xy          4     NONE  float   xy  
// NORMAL                   3   xyzw        5     NONE  float   xyzw
// BLENDINDICES             0   xyzw        6     NONE   uint   x   
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_POSITION              0   xyzw        0      POS  float   xyzw
// TEXCOORD                 0   xy          1     NONE  float   xy  
// TEXCOORD                 4     zw        1     NONE  float     zw
// TEXCOORD                 1   xyz         2     NONE  float   xyz 
// TEXCOORD                 5      w        2     NONE  float      w
// TEXCOORD                 2   xyz         3     NONE  float   xyz 
// TEXCOORD                 3   xyz         4     NONE  float   xyz 
// TEXCOORD                 6   xy          5     NONE  float   xy  
// TEXCOORD                 7     z         5     NONE  float     z 
// COLOR                    0   xyzw        6     NONE  float   xyzw
//
vs_4_0
dcl_constantbuffer cb0[369], dynamicIndexed
dcl_input v0.xyz
dcl_input v1.xyz
dcl_input v2.xyz
dcl_input v3.xyz
dcl_input v4.xy
dcl_input v5.xyzw
dcl_input v6.x
dcl_output_siv o0.xyzw, position
dcl_output o1.xy
dcl_output o1.zw
dcl_output o2.xyz
dcl_output o2.w
dcl_output o3.xyz
dcl_output o4.xyz
dcl_output o5.xy
dcl_output o5.z
dcl_output o6.xyzw
dcl_temps 5
ishl r0.x, v6.x, l(2)
mov r0.y, v6.x
mul o6.xyzw, v5.xyzw, cb0[r0.y + 325].xyzw
mul r1.xyzw, v0.yyyy, cb0[r0.x + 5].xyzw
mad r1.xyzw, cb0[r0.x + 4].xyzw, v0.xxxx, r1.xyzw
mad r1.xyzw, cb0[r0.x + 6].xyzw, v0.zzzz, r1.xyzw
add r1.xyzw, r1.xyzw, cb0[r0.x + 7].xyzw
mul r2.xyzw, r1.yyyy, cb0[1].xyzw
mad r2.xyzw, cb0[0].xyzw, r1.xxxx, r2.xyzw
mad r2.xyzw, cb0[2].xyzw, r1.zzzz, r2.xyzw
mad o0.xyzw, cb0[3].xyzw, r1.wwww, r2.xyzw
mad r0.zw, v4.xxxy, cb0[r0.y + 164].zzzw, cb0[r0.y + 164].xxxy
mad r1.xy, v4.xyxx, cb0[r0.y + 204].zwzz, cb0[r0.y + 204].xyxx
lt r1.z, l(0.000000), cb0[244].x
if_nz r1.z
  frc o2.w, cb0[r0.y + 245].x
  round_ni r2.x, cb0[r0.y + 245].x
  add r1.z, l(1.000000), cb0[r0.y + 245].x
  eq r1.w, cb0[244].y, l(0.000000)
  if_nz r1.w
    mul r1.w, cb0[244].w, cb0[244].z
    ge r1.w, r1.z, r1.w
    mad r2.w, cb0[244].z, cb0[244].w, l(-1.000000)
    add r2.z, l(1.000000), cb0[r0.y + 245].x
    movc r2.xy, r1.wwww, r2.wwww, r2.xzxx
  else 
    mul r1.w, cb0[244].w, cb0[244].z
    mul r2.z, r1.w, r1.z
    ge r2.z, r2.z, -r2.z
    movc r2.z, r2.z, r1.w, -r1.w
    div r2.w, l(1.000000, 1.000000, 1.000000, 1.000000), r2.z
    mul r2.w, r1.z, r2.w
    frc r2.w, r2.w
    mul r2.z, r2.w, r2.z
    eq r3.xy, cb0[244].yyyy, l(1.000000, 2.000000, 0.000000, 0.000000)
    round_ni r2.w, r1.z
    div r2.w, r2.w, r1.w
    add r3.z, r2.w, r2.w
    ge r3.z, r3.z, -r3.z
    movc r3.zw, r3.zzzz, l(0,0,2.000000,0.500000), l(0,0,-2.000000,-0.500000)
    mul r2.w, r2.w, r3.w
    frc r2.w, r2.w
    mul r2.w, r2.w, r3.z
    eq r2.w, r2.w, l(1.000000)
    round_z r3.z, r1.z
    mul r3.w, r1.w, r3.z
    ge r3.w, r3.w, -r3.w
    movc r1.w, r3.w, r1.w, -r1.w
    div r3.w, l(1.000000, 1.000000, 1.000000, 1.000000), r1.w
    mul r3.z, r3.w, r3.z
    frc r3.z, r3.z
    mul r3.w, r1.w, r3.z
    mad r4.x, cb0[244].z, cb0[244].w, l(-1.000000)
    mad r1.w, -r1.w, r3.z, r4.x
    movc r1.w, r2.w, r1.w, r3.w
    movc r1.z, r3.y, r1.w, r1.z
    movc r2.y, r3.x, r2.z, r1.z
  endif 
  ftoi r1.zw, r2.xxxy
  ftoi r2.xy, cb0[244].zwzz
  and r2.zw, r1.zzzw, l(0, 0, 0x80000000, 0x80000000)
  imax r3.xy, r1.zwzz, -r1.zwzz
  imax r3.zw, r2.xxxy, -r2.xxxy
  udiv null, r4.xy, r3.xyxx, r3.zzzz
  ineg r4.zw, r4.xxxy
  movc r2.xz, r2.zzwz, r4.zzwz, r4.xxyx
  itof r4.xy, r2.xzxx
  xor r1.zw, r1.zzzw, r2.yyyy
  udiv r2.xy, null, r3.xyxx, r3.wwww
  ineg r2.zw, r2.xxxy
  and r1.zw, r1.zzzw, l(0, 0, 0x80000000, 0x80000000)
  movc r1.zw, r1.zzzw, r2.zzzw, r2.xxxy
  itof r4.zw, r1.zzzw
  div r1.zw, l(1.000000, 1.000000, 1.000000, 1.000000), cb0[244].zzzw
  mul r2.xy, r1.zwzz, r4.ywyy
  mad r2.zw, -r4.xxxz, r1.zzzw, r0.zzzw
  mul r2.zw, r2.zzzw, cb0[244].zzzw
  mad r2.xy, r2.zwzz, r1.zwzz, r2.xyxx
else 
  mov r2.xy, l(0,0,0,0)
  mov o2.w, l(0)
endif 
mul r3.xyz, v1.yyyy, cb0[r0.x + 5].xyzx
mad r3.xyz, cb0[r0.x + 4].xyzx, v1.xxxx, r3.xyzx
mad r3.xyz, cb0[r0.x + 6].xyzx, v1.zzzz, r3.xyzx
dp3 r1.z, r3.xyzx, r3.xyzx
rsq r1.z, r1.z
mul o2.xyz, r1.zzzz, r3.xyzx
mul r3.xyz, v2.yyyy, cb0[r0.x + 5].xyzx
mad r3.xyz, cb0[r0.x + 4].xyzx, v2.xxxx, r3.xyzx
mad r3.xyz, cb0[r0.x + 6].xyzx, v2.zzzz, r3.xyzx
dp3 r1.z, r3.xyzx, r3.xyzx
rsq r1.z, r1.z
mul o3.xyz, r1.zzzz, r3.xyzx
mul r3.xyz, v3.yyyy, cb0[r0.x + 5].xyzx
mad r3.xyz, cb0[r0.x + 4].xyzx, v3.xxxx, r3.xyzx
mad r3.xyz, cb0[r0.x + 6].xyzx, v3.zzzz, r3.xyzx
dp3 r0.x, r3.xyzx, r3.xyzx
rsq r0.x, r0.x
mul o4.xyz, r0.xxxx, r3.xyzx
mad o1.y, cb0[368].y, r0.w, cb0[368].x
mad o1.w, cb0[368].y, r1.y, cb0[368].x
mov o1.x, r0.z
mov o1.z, r1.x
mov r2.z, cb0[r0.y + 285].x
mov o5.xyz, r2.xyzx
ret 
// Approximately 107 instruction slots used
#endif

const BYTE g_VS[] =
{
     68,  88,  66,  67, 232, 250, 
    242, 151, 186, 245, 147, 197, 
    109, 178,  26, 186,  79, 162, 
     73, 159,   1,   0,   0,   0, 
    228,  19,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
     36,   3,   0,   0,   4,   4, 
      0,   0,  32,   5,   0,   0, 
    104,  19,   0,   0,  82,  68, 
     69,  70, 232,   2,   0,   0, 
      1,   0,   0,   0,  80,   0, 
      0,   0,   1,   0,   0,   0, 
     28,   0,   0,   0,   0,   4, 
    254, 255,  16,   1,   0,   0, 
    182,   2,   0,   0,  60,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     86,  83,  95,  67, 111, 110, 
    115, 116,  97, 110, 116,  66, 
    117, 102, 102, 101, 114,   0, 
    171, 171,  60,   0,   0,   0, 
     12,   0,   0,   0, 104,   0, 
      0,   0,  16,  23,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 136,   1,   0,   0, 
      0,   0,   0,   0,  64,   0, 
      0,   0,   2,   0,   0,   0, 
    148,   1,   0,   0,   0,   0, 
      0,   0, 164,   1,   0,   0, 
     64,   0,   0,   0,   0,  10, 
      0,   0,   2,   0,   0,   0, 
    172,   1,   0,   0,   0,   0, 
      0,   0, 188,   1,   0,   0, 
     64,  10,   0,   0, 128,   2, 
      0,   0,   2,   0,   0,   0, 
    192,   1,   0,   0,   0,   0, 
      0,   0, 208,   1,   0,   0, 
    192,  12,   0,   0, 128,   2, 
      0,   0,   2,   0,   0,   0, 
    220,   1,   0,   0,   0,   0, 
      0,   0, 236,   1,   0,   0, 
     64,  15,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   2,   0,   0,   0,   0, 
      0,   0,  16,   2,   0,   0, 
     80,  15,   0,   0, 128,   2, 
      0,   0,   2,   0,   0,   0, 
     44,   2,   0,   0,   0,   0, 
      0,   0,  60,   2,   0,   0, 
    208,  17,   0,   0, 128,   2, 
      0,   0,   2,   0,   0,   0, 
     84,   2,   0,   0,   0,   0, 
      0,   0, 100,   2,   0,   0, 
     80,  20,   0,   0, 128,   2, 
      0,   0,   2,   0,   0,   0, 
    112,   2,   0,   0,   0,   0, 
      0,   0, 128,   2,   0,   0, 
    208,  22,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   2,   0,   0,   0,   0, 
      0,   0, 144,   2,   0,   0, 
    224,  22,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   2,   0,   0,   0,   0, 
      0,   0, 156,   2,   0,   0, 
    240,  22,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   2,   0,   0,   0,   0, 
      0,   0, 170,   2,   0,   0, 
      0,  23,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   2,   0,   0,   0,   0, 
      0,   0, 109,  67,  97, 109, 
    101, 114,  97,  80, 114, 111, 
    106,   0,   3,   0,   3,   0, 
      4,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    109,  77, 111, 100, 101, 108, 
      0, 171,   3,   0,   3,   0, 
      4,   0,   4,   0,  40,   0, 
      0,   0,   0,   0,   0,   0, 
    102,  85,  86,   0,   1,   0, 
      3,   0,   1,   0,   4,   0, 
     40,   0,   0,   0,   0,   0, 
      0,   0, 102,  65, 108, 112, 
    104,  97,  85,  86,   0, 171, 
    171, 171,   1,   0,   3,   0, 
      1,   0,   4,   0,  40,   0, 
      0,   0,   0,   0,   0,   0, 
    102,  70, 108, 105, 112,  98, 
    111, 111, 107,  80,  97, 114, 
     97, 109, 101, 116, 101, 114, 
      0, 171,   1,   0,   3,   0, 
      1,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    102,  70, 108, 105, 112,  98, 
    111, 111, 107,  73, 110, 100, 
    101, 120,  65, 110, 100,  78, 
    101, 120, 116,  82,  97, 116, 
    101,   0, 171, 171,   1,   0, 
      3,   0,   1,   0,   4,   0, 
     40,   0,   0,   0,   0,   0, 
      0,   0, 102,  77, 111, 100, 
    101, 108,  65, 108, 112, 104, 
     97,  84, 104, 114, 101, 115, 
    104, 111, 108, 100,   0, 171, 
    171, 171,   1,   0,   3,   0, 
      1,   0,   4,   0,  40,   0, 
      0,   0,   0,   0,   0,   0, 
    102,  77, 111, 100, 101, 108, 
     67, 111, 108, 111, 114,   0, 
      1,   0,   3,   0,   1,   0, 
      4,   0,  40,   0,   0,   0, 
      0,   0,   0,   0, 102,  76, 
    105, 103, 104, 116,  68, 105, 
    114, 101,  99, 116, 105, 111, 
    110,   0, 102,  76, 105, 103, 
    104, 116,  67, 111, 108, 111, 
    114,   0, 102,  76, 105, 103, 
    104, 116,  65, 109,  98, 105, 
    101, 110, 116,   0, 109,  85, 
     86,  73, 110, 118, 101, 114, 
    115, 101, 100,   0,  77, 105, 
     99, 114, 111, 115, 111, 102, 
    116,  32,  40,  82,  41,  32, 
     72,  76,  83,  76,  32,  83, 
    104,  97, 100, 101, 114,  32, 
     67, 111, 109, 112, 105, 108, 
    101, 114,  32,  57,  46,  50, 
     57,  46,  57,  53,  50,  46, 
     51,  49,  49,  49,   0, 171, 
     73,  83,  71,  78, 216,   0, 
      0,   0,   7,   0,   0,   0, 
      8,   0,   0,   0, 176,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      7,   7,   0,   0, 185,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
      7,   7,   0,   0, 185,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
      7,   7,   0,   0, 185,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   3,   0,   0,   0, 
      7,   7,   0,   0, 192,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   4,   0,   0,   0, 
      3,   3,   0,   0, 185,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   5,   0,   0,   0, 
     15,  15,   0,   0, 201,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   6,   0,   0,   0, 
     15,   1,   0,   0,  80,  79, 
     83,  73,  84,  73,  79,  78, 
      0,  78,  79,  82,  77,  65, 
     76,   0,  84,  69,  88,  67, 
     79,  79,  82,  68,   0,  66, 
     76,  69,  78,  68,  73,  78, 
     68,  73,  67,  69,  83,   0, 
    171, 171,  79,  83,  71,  78, 
     20,   1,   0,   0,  10,   0, 
      0,   0,   8,   0,   0,   0, 
    248,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
      4,   1,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,   3,  12,   0,   0, 
      4,   1,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,  12,   3,   0,   0, 
      4,   1,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,   7,   8,   0,   0, 
      4,   1,   0,   0,   5,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,   8,   7,   0,   0, 
      4,   1,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   3,   0, 
      0,   0,   7,   8,   0,   0, 
      4,   1,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   4,   0, 
      0,   0,   7,   8,   0,   0, 
      4,   1,   0,   0,   6,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   5,   0, 
      0,   0,   3,  12,   0,   0, 
      4,   1,   0,   0,   7,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   5,   0, 
      0,   0,   4,  11,   0,   0, 
     13,   1,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   6,   0, 
      0,   0,  15,   0,   0,   0, 
     83,  86,  95,  80,  79,  83, 
     73,  84,  73,  79,  78,   0, 
     84,  69,  88,  67,  79,  79, 
     82,  68,   0,  67,  79,  76, 
     79,  82,   0, 171,  83,  72, 
     68,  82,  64,  14,   0,   0, 
     64,   0,   1,   0, 144,   3, 
      0,   0,  89,   8,   0,   4, 
     70, 142,  32,   0,   0,   0, 
      0,   0, 113,   1,   0,   0, 
     95,   0,   0,   3, 114,  16, 
     16,   0,   0,   0,   0,   0, 
     95,   0,   0,   3, 114,  16, 
     16,   0,   1,   0,   0,   0, 
     95,   0,   0,   3, 114,  16, 
     16,   0,   2,   0,   0,   0, 
     95,   0,   0,   3, 114,  16, 
     16,   0,   3,   0,   0,   0, 
     95,   0,   0,   3,  50,  16, 
     16,   0,   4,   0,   0,   0, 
     95,   0,   0,   3, 242,  16, 
     16,   0,   5,   0,   0,   0, 
     95,   0,   0,   3,  18,  16, 
     16,   0,   6,   0,   0,   0, 
    103,   0,   0,   4, 242,  32, 
     16,   0,   0,   0,   0,   0, 
      1,   0,   0,   0, 101,   0, 
      0,   3,  50,  32,  16,   0, 
      1,   0,   0,   0, 101,   0, 
      0,   3, 194,  32,  16,   0, 
      1,   0,   0,   0, 101,   0, 
      0,   3, 114,  32,  16,   0, 
      2,   0,   0,   0, 101,   0, 
      0,   3, 130,  32,  16,   0, 
      2,   0,   0,   0, 101,   0, 
      0,   3, 114,  32,  16,   0, 
      3,   0,   0,   0, 101,   0, 
      0,   3, 114,  32,  16,   0, 
      4,   0,   0,   0, 101,   0, 
      0,   3,  50,  32,  16,   0, 
      5,   0,   0,   0, 101,   0, 
      0,   3,  66,  32,  16,   0, 
      5,   0,   0,   0, 101,   0, 
      0,   3, 242,  32,  16,   0, 
      6,   0,   0,   0, 104,   0, 
      0,   2,   5,   0,   0,   0, 
     41,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,  16,  16,   0,   6,   0, 
      0,   0,   1,  64,   0,   0, 
      2,   0,   0,   0,  54,   0, 
      0,   5,  34,   0,  16,   0, 
      0,   0,   0,   0,  10,  16, 
     16,   0,   6,   0,   0,   0, 
     56,   0,   0,  10, 242,  32, 
     16,   0,   6,   0,   0,   0, 
     70,  30,  16,   0,   5,   0, 
      0,   0,  70, 142,  32,   6, 
      0,   0,   0,   0,  69,   1, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,  10, 242,   0,  16,   0, 
      1,   0,   0,   0,  86,  21, 
     16,   0,   0,   0,   0,   0, 
     70, 142,  32,   6,   0,   0, 
      0,   0,   5,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  50,   0,   0,  12, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  70, 142,  32,   6, 
      0,   0,   0,   0,   4,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   6,  16, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  50,   0,   0,  12, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  70, 142,  32,   6, 
      0,   0,   0,   0,   6,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0, 166,  26, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,   0,   0,   0,  10, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  70, 142, 
     32,   6,   0,   0,   0,   0, 
      7,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   8, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     86,   5,  16,   0,   1,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  50,   0,   0,  10, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   6,   0,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
    166,  10,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  50,   0, 
      0,  10, 242,  32,  16,   0, 
      0,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      3,   0,   0,   0, 246,  15, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  50,   0,   0,  15, 
    194,   0,  16,   0,   0,   0, 
      0,   0,   6,  20,  16,   0, 
      4,   0,   0,   0, 166, 142, 
     32,   6,   0,   0,   0,   0, 
    164,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
      6, 132,  32,   6,   0,   0, 
      0,   0, 164,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  50,   0,   0,  15, 
     50,   0,  16,   0,   1,   0, 
      0,   0,  70,  16,  16,   0, 
      4,   0,   0,   0, 230, 138, 
     32,   6,   0,   0,   0,   0, 
    204,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     70, 128,  32,   6,   0,   0, 
      0,   0, 204,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  49,   0,   0,   8, 
     66,   0,  16,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  10, 128, 
     32,   0,   0,   0,   0,   0, 
    244,   0,   0,   0,  31,   0, 
      4,   3,  42,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
      0,   8, 130,  32,  16,   0, 
      2,   0,   0,   0,  10, 128, 
     32,   6,   0,   0,   0,   0, 
    245,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     65,   0,   0,   8,  18,   0, 
     16,   0,   2,   0,   0,   0, 
     10, 128,  32,   6,   0,   0, 
      0,   0, 245,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,  10, 
     66,   0,  16,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128,  63,  10, 128, 
     32,   6,   0,   0,   0,   0, 
    245,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     24,   0,   0,   8, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     26, 128,  32,   0,   0,   0, 
      0,   0, 244,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  31,   0,   4,   3, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,   9, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  58, 128,  32,   0, 
      0,   0,   0,   0, 244,   0, 
      0,   0,  42, 128,  32,   0, 
      0,   0,   0,   0, 244,   0, 
      0,   0,  29,   0,   0,   7, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     50,   0,   0,  11, 130,   0, 
     16,   0,   2,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0, 244,   0,   0,   0, 
     58, 128,  32,   0,   0,   0, 
      0,   0, 244,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128, 191,   0,   0,   0,  10, 
     66,   0,  16,   0,   2,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128,  63,  10, 128, 
     32,   6,   0,   0,   0,   0, 
    245,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     55,   0,   0,   9,  50,   0, 
     16,   0,   2,   0,   0,   0, 
    246,  15,  16,   0,   1,   0, 
      0,   0, 246,  15,  16,   0, 
      2,   0,   0,   0, 134,   0, 
     16,   0,   2,   0,   0,   0, 
     18,   0,   0,   1,  56,   0, 
      0,   9, 130,   0,  16,   0, 
      1,   0,   0,   0,  58, 128, 
     32,   0,   0,   0,   0,   0, 
    244,   0,   0,   0,  42, 128, 
     32,   0,   0,   0,   0,   0, 
    244,   0,   0,   0,  56,   0, 
      0,   7,  66,   0,  16,   0, 
      2,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  29,   0,   0,   8, 
     66,   0,  16,   0,   2,   0, 
      0,   0,  42,   0,  16,   0, 
      2,   0,   0,   0,  42,   0, 
     16, 128,  65,   0,   0,   0, 
      2,   0,   0,   0,  55,   0, 
      0,  10,  66,   0,  16,   0, 
      2,   0,   0,   0,  42,   0, 
     16,   0,   2,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16, 128, 
     65,   0,   0,   0,   1,   0, 
      0,   0,  14,   0,   0,  10, 
    130,   0,  16,   0,   2,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0, 128,  63, 
      0,   0, 128,  63,  42,   0, 
     16,   0,   2,   0,   0,   0, 
     56,   0,   0,   7, 130,   0, 
     16,   0,   2,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      2,   0,   0,   0,  26,   0, 
      0,   5, 130,   0,  16,   0, 
      2,   0,   0,   0,  58,   0, 
     16,   0,   2,   0,   0,   0, 
     56,   0,   0,   7,  66,   0, 
     16,   0,   2,   0,   0,   0, 
     58,   0,  16,   0,   2,   0, 
      0,   0,  42,   0,  16,   0, 
      2,   0,   0,   0,  24,   0, 
      0,  11,  50,   0,  16,   0, 
      3,   0,   0,   0,  86, 133, 
     32,   0,   0,   0,   0,   0, 
    244,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128,  63, 
      0,   0,   0,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     65,   0,   0,   5, 130,   0, 
     16,   0,   2,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  14,   0,   0,   7, 
    130,   0,  16,   0,   2,   0, 
      0,   0,  58,   0,  16,   0, 
      2,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
      0,   0,   0,   7,  66,   0, 
     16,   0,   3,   0,   0,   0, 
     58,   0,  16,   0,   2,   0, 
      0,   0,  58,   0,  16,   0, 
      2,   0,   0,   0,  29,   0, 
      0,   8,  66,   0,  16,   0, 
      3,   0,   0,   0,  42,   0, 
     16,   0,   3,   0,   0,   0, 
     42,   0,  16, 128,  65,   0, 
      0,   0,   3,   0,   0,   0, 
     55,   0,   0,  15, 194,   0, 
     16,   0,   3,   0,   0,   0, 
    166,  10,  16,   0,   3,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,  64, 
      0,   0,   0,  63,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0, 192,   0,   0,   0, 191, 
     56,   0,   0,   7, 130,   0, 
     16,   0,   2,   0,   0,   0, 
     58,   0,  16,   0,   2,   0, 
      0,   0,  58,   0,  16,   0, 
      3,   0,   0,   0,  26,   0, 
      0,   5, 130,   0,  16,   0, 
      2,   0,   0,   0,  58,   0, 
     16,   0,   2,   0,   0,   0, 
     56,   0,   0,   7, 130,   0, 
     16,   0,   2,   0,   0,   0, 
     58,   0,  16,   0,   2,   0, 
      0,   0,  42,   0,  16,   0, 
      3,   0,   0,   0,  24,   0, 
      0,   7, 130,   0,  16,   0, 
      2,   0,   0,   0,  58,   0, 
     16,   0,   2,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  67,   0,   0,   5, 
     66,   0,  16,   0,   3,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  56,   0, 
      0,   7, 130,   0,  16,   0, 
      3,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     42,   0,  16,   0,   3,   0, 
      0,   0,  29,   0,   0,   8, 
    130,   0,  16,   0,   3,   0, 
      0,   0,  58,   0,  16,   0, 
      3,   0,   0,   0,  58,   0, 
     16, 128,  65,   0,   0,   0, 
      3,   0,   0,   0,  55,   0, 
      0,  10, 130,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   3,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16, 128, 
     65,   0,   0,   0,   1,   0, 
      0,   0,  14,   0,   0,  10, 
    130,   0,  16,   0,   3,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0, 128,  63, 
      0,   0, 128,  63,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     56,   0,   0,   7,  66,   0, 
     16,   0,   3,   0,   0,   0, 
     58,   0,  16,   0,   3,   0, 
      0,   0,  42,   0,  16,   0, 
      3,   0,   0,   0,  26,   0, 
      0,   5,  66,   0,  16,   0, 
      3,   0,   0,   0,  42,   0, 
     16,   0,   3,   0,   0,   0, 
     56,   0,   0,   7, 130,   0, 
     16,   0,   3,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      3,   0,   0,   0,  50,   0, 
      0,  11,  18,   0,  16,   0, 
      4,   0,   0,   0,  42, 128, 
     32,   0,   0,   0,   0,   0, 
    244,   0,   0,   0,  58, 128, 
     32,   0,   0,   0,   0,   0, 
    244,   0,   0,   0,   1,  64, 
      0,   0,   0,   0, 128, 191, 
     50,   0,   0,  10, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
     42,   0,  16,   0,   3,   0, 
      0,   0,  10,   0,  16,   0, 
      4,   0,   0,   0,  55,   0, 
      0,   9, 130,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   2,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      3,   0,   0,   0,  55,   0, 
      0,   9,  66,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   3,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  55,   0, 
      0,   9,  34,   0,  16,   0, 
      2,   0,   0,   0,  10,   0, 
     16,   0,   3,   0,   0,   0, 
     42,   0,  16,   0,   2,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  21,   0, 
      0,   1,  27,   0,   0,   5, 
    194,   0,  16,   0,   1,   0, 
      0,   0,   6,   4,  16,   0, 
      2,   0,   0,   0,  27,   0, 
      0,   6,  50,   0,  16,   0, 
      2,   0,   0,   0, 230, 138, 
     32,   0,   0,   0,   0,   0, 
    244,   0,   0,   0,   1,   0, 
      0,  10, 194,   0,  16,   0, 
      2,   0,   0,   0, 166,  14, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0, 128,   0,   0, 
      0, 128,  36,   0,   0,   8, 
     50,   0,  16,   0,   3,   0, 
      0,   0, 230,  10,  16,   0, 
      1,   0,   0,   0, 230,  10, 
     16, 128,  65,   0,   0,   0, 
      1,   0,   0,   0,  36,   0, 
      0,   8, 194,   0,  16,   0, 
      3,   0,   0,   0,   6,   4, 
     16,   0,   2,   0,   0,   0, 
      6,   4,  16, 128,  65,   0, 
      0,   0,   2,   0,   0,   0, 
     78,   0,   0,   8,   0, 208, 
      0,   0,  50,   0,  16,   0, 
      4,   0,   0,   0,  70,   0, 
     16,   0,   3,   0,   0,   0, 
    166,  10,  16,   0,   3,   0, 
      0,   0,  40,   0,   0,   5, 
    194,   0,  16,   0,   4,   0, 
      0,   0,   6,   4,  16,   0, 
      4,   0,   0,   0,  55,   0, 
      0,   9,  82,   0,  16,   0, 
      2,   0,   0,   0, 166,  11, 
     16,   0,   2,   0,   0,   0, 
    166,  11,  16,   0,   4,   0, 
      0,   0,   6,   1,  16,   0, 
      4,   0,   0,   0,  43,   0, 
      0,   5,  50,   0,  16,   0, 
      4,   0,   0,   0, 134,   0, 
     16,   0,   2,   0,   0,   0, 
     87,   0,   0,   7, 194,   0, 
     16,   0,   1,   0,   0,   0, 
    166,  14,  16,   0,   1,   0, 
      0,   0,  86,   5,  16,   0, 
      2,   0,   0,   0,  78,   0, 
      0,   8,  50,   0,  16,   0, 
      2,   0,   0,   0,   0, 208, 
      0,   0,  70,   0,  16,   0, 
      3,   0,   0,   0, 246,  15, 
     16,   0,   3,   0,   0,   0, 
     40,   0,   0,   5, 194,   0, 
     16,   0,   2,   0,   0,   0, 
      6,   4,  16,   0,   2,   0, 
      0,   0,   1,   0,   0,  10, 
    194,   0,  16,   0,   1,   0, 
      0,   0, 166,  14,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0, 128,   0,   0,   0, 128, 
     55,   0,   0,   9, 194,   0, 
     16,   0,   1,   0,   0,   0, 
    166,  14,  16,   0,   1,   0, 
      0,   0, 166,  14,  16,   0, 
      2,   0,   0,   0,   6,   4, 
     16,   0,   2,   0,   0,   0, 
     43,   0,   0,   5, 194,   0, 
     16,   0,   4,   0,   0,   0, 
    166,  14,  16,   0,   1,   0, 
      0,   0,  14,   0,   0,  11, 
    194,   0,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0, 128,  63, 
      0,   0, 128,  63, 166, 142, 
     32,   0,   0,   0,   0,   0, 
    244,   0,   0,   0,  56,   0, 
      0,   7,  50,   0,  16,   0, 
      2,   0,   0,   0, 230,  10, 
     16,   0,   1,   0,   0,   0, 
    214,   5,  16,   0,   4,   0, 
      0,   0,  50,   0,   0,  10, 
    194,   0,  16,   0,   2,   0, 
      0,   0,   6,   8,  16, 128, 
     65,   0,   0,   0,   4,   0, 
      0,   0, 166,  14,  16,   0, 
      1,   0,   0,   0, 166,  14, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   8, 194,   0, 
     16,   0,   2,   0,   0,   0, 
    166,  14,  16,   0,   2,   0, 
      0,   0, 166, 142,  32,   0, 
      0,   0,   0,   0, 244,   0, 
      0,   0,  50,   0,   0,   9, 
     50,   0,  16,   0,   2,   0, 
      0,   0, 230,  10,  16,   0, 
      2,   0,   0,   0, 230,  10, 
     16,   0,   1,   0,   0,   0, 
     70,   0,  16,   0,   2,   0, 
      0,   0,  18,   0,   0,   1, 
     54,   0,   0,   8,  50,   0, 
     16,   0,   2,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  54,   0,   0,   5, 
    130,  32,  16,   0,   2,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  21,   0, 
      0,   1,  56,   0,   0,  10, 
    114,   0,  16,   0,   3,   0, 
      0,   0,  86,  21,  16,   0, 
      1,   0,   0,   0,  70, 130, 
     32,   6,   0,   0,   0,   0, 
      5,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     50,   0,   0,  12, 114,   0, 
     16,   0,   3,   0,   0,   0, 
     70, 130,  32,   6,   0,   0, 
      0,   0,   4,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,   6,  16,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   3,   0,   0,   0, 
     50,   0,   0,  12, 114,   0, 
     16,   0,   3,   0,   0,   0, 
     70, 130,  32,   6,   0,   0, 
      0,   0,   6,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0, 166,  26,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   3,   0,   0,   0, 
     16,   0,   0,   7,  66,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   3,   0, 
      0,   0,  70,   2,  16,   0, 
      3,   0,   0,   0,  68,   0, 
      0,   5,  66,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
     56,   0,   0,   7, 114,  32, 
     16,   0,   2,   0,   0,   0, 
    166,  10,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      3,   0,   0,   0,  56,   0, 
      0,  10, 114,   0,  16,   0, 
      3,   0,   0,   0,  86,  21, 
     16,   0,   2,   0,   0,   0, 
     70, 130,  32,   6,   0,   0, 
      0,   0,   5,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  50,   0,   0,  12, 
    114,   0,  16,   0,   3,   0, 
      0,   0,  70, 130,  32,   6, 
      0,   0,   0,   0,   4,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   6,  16, 
     16,   0,   2,   0,   0,   0, 
     70,   2,  16,   0,   3,   0, 
      0,   0,  50,   0,   0,  12, 
    114,   0,  16,   0,   3,   0, 
      0,   0,  70, 130,  32,   6, 
      0,   0,   0,   0,   6,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0, 166,  26, 
     16,   0,   2,   0,   0,   0, 
     70,   2,  16,   0,   3,   0, 
      0,   0,  16,   0,   0,   7, 
     66,   0,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      3,   0,   0,   0,  70,   2, 
     16,   0,   3,   0,   0,   0, 
     68,   0,   0,   5,  66,   0, 
     16,   0,   1,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,   7, 
    114,  32,  16,   0,   3,   0, 
      0,   0, 166,  10,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   3,   0,   0,   0, 
     56,   0,   0,  10, 114,   0, 
     16,   0,   3,   0,   0,   0, 
     86,  21,  16,   0,   3,   0, 
      0,   0,  70, 130,  32,   6, 
      0,   0,   0,   0,   5,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  50,   0, 
      0,  12, 114,   0,  16,   0, 
      3,   0,   0,   0,  70, 130, 
     32,   6,   0,   0,   0,   0, 
      4,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
      6,  16,  16,   0,   3,   0, 
      0,   0,  70,   2,  16,   0, 
      3,   0,   0,   0,  50,   0, 
      0,  12, 114,   0,  16,   0, 
      3,   0,   0,   0,  70, 130, 
     32,   6,   0,   0,   0,   0, 
      6,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
    166,  26,  16,   0,   3,   0, 
      0,   0,  70,   2,  16,   0, 
      3,   0,   0,   0,  16,   0, 
      0,   7,  18,   0,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   3,   0,   0,   0, 
     70,   2,  16,   0,   3,   0, 
      0,   0,  68,   0,   0,   5, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   7, 114,  32,  16,   0, 
      4,   0,   0,   0,   6,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   3,   0, 
      0,   0,  50,   0,   0,  11, 
     34,  32,  16,   0,   1,   0, 
      0,   0,  26, 128,  32,   0, 
      0,   0,   0,   0, 112,   1, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  10, 128, 
     32,   0,   0,   0,   0,   0, 
    112,   1,   0,   0,  50,   0, 
      0,  11, 130,  32,  16,   0, 
      1,   0,   0,   0,  26, 128, 
     32,   0,   0,   0,   0,   0, 
    112,   1,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     10, 128,  32,   0,   0,   0, 
      0,   0, 112,   1,   0,   0, 
     54,   0,   0,   5,  18,  32, 
     16,   0,   1,   0,   0,   0, 
     42,   0,  16,   0,   0,   0, 
      0,   0,  54,   0,   0,   5, 
     66,  32,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,  54,   0, 
      0,   8,  66,   0,  16,   0, 
      2,   0,   0,   0,  10, 128, 
     32,   6,   0,   0,   0,   0, 
     29,   1,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     54,   0,   0,   5, 114,  32, 
     16,   0,   5,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,  62,   0,   0,   1, 
     83,  84,  65,  84, 116,   0, 
      0,   0, 107,   0,   0,   0, 
      5,   0,   0,   0,   0,   0, 
      0,   0,  17,   0,   0,   0, 
     50,   0,   0,   0,   5,   0, 
      0,   0,   5,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     14,   0,   0,   0,   9,   0, 
      0,   0,  11,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0
};
