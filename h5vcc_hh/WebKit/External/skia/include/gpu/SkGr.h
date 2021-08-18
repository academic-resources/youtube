/*
    Copyright 2010 Google Inc.

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

         http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
 */


#ifndef SkGr_DEFINED
#define SkGr_DEFINED

#include <stddef.h>

// tetrark headers
#include "GrConfig.h"
#include "GrContext.h"
#include "GrFontScaler.h"
#include "GrPathIter.h"
#include "GrClipIterator.h"

// skia headers
#include "SkBitmap.h"
#include "SkPath.h"
#include "SkPoint.h"
#include "SkRegion.h"
#include "SkShader.h"

#if (GR_DEBUG && defined(SK_RELEASE)) || (GR_RELEASE && defined(SK_DEBUG))
//    #error "inconsistent GR_DEBUG and SK_DEBUG"
#endif

#if GR_SCALAR_IS_FIXED
    #ifdef SK_SCALAR_IS_FIXED
        #define SK_SCALAR_IS_GR_SCALAR  1
    #else
        #define SK_SCALAR_IS_GR_SCALAR  0
    #endif
    #define SkScalarToGrScalar(x)       SkScalarToFixed(x)

#elif GR_SCALAR_IS_FLOAT

    #ifdef SK_SCALAR_IS_FLOAT
        #define SK_SCALAR_IS_GR_SCALAR  1
    #else
        #define SK_SCALAR_IS_GR_SCALAR  0
    #endif
    #define SkScalarToGrScalar(x)       SkScalarToFloat(x)

#else
    #error "Ganesh scalar type not defined"
#endif

////////////////////////////////////////////////////////////////////////////////
// Sk to Gr Type conversions

// Verify that SkPoint and GrPoint are compatible if using the same scalar type
#if 0/*SK_SCALAR_IS_GR_SCALAR*/
    GR_STATIC_ASSERT(sizeof(SkPoint) == sizeof(GrPoint));
    GR_STATIC_ASSERT(offsetof(SkPoint,fX) == offsetof(GrPoint,fX)));
    GR_STATIC_ASSERT(offsetof(SkPoint,fY) == offsetof(GrPoint,fY)));
#endif

GR_STATIC_ASSERT((int)GrSamplerState::kClamp_WrapMode == (int)SkShader::kClamp_TileMode);
GR_STATIC_ASSERT((int)GrSamplerState::kRepeat_WrapMode ==(
                 int)SkShader::kRepeat_TileMode);
GR_STATIC_ASSERT((int)GrSamplerState::kMirror_WrapMode ==
                 (int)SkShader::kMirror_TileMode);

#define sk_tile_mode_to_grwrap(X) ((GrSamplerState::WrapMode)(X))

GR_STATIC_ASSERT((int)GrGpu::kZero_BlendCoeff == (int)SkXfermode::kZero_Coeff);
GR_STATIC_ASSERT((int)GrGpu::kOne_BlendCoeff  == (int)SkXfermode::kOne_Coeff);
GR_STATIC_ASSERT((int)GrGpu::kSC_BlendCoeff   == (int)SkXfermode::kSC_Coeff);
GR_STATIC_ASSERT((int)GrGpu::kISC_BlendCoeff  == (int)SkXfermode::kISC_Coeff);
GR_STATIC_ASSERT((int)GrGpu::kDC_BlendCoeff   == (int)SkXfermode::kDC_Coeff);
GR_STATIC_ASSERT((int)GrGpu::kIDC_BlendCoeff  == (int)SkXfermode::kIDC_Coeff);
GR_STATIC_ASSERT((int)GrGpu::kSA_BlendCoeff   == (int)SkXfermode::kSA_Coeff);
GR_STATIC_ASSERT((int)GrGpu::kISA_BlendCoeff  == (int)SkXfermode::kISA_Coeff);
GR_STATIC_ASSERT((int)GrGpu::kDA_BlendCoeff   == (int)SkXfermode::kDA_Coeff);
GR_STATIC_ASSERT((int)GrGpu::kIDA_BlendCoeff  == (int)SkXfermode::kIDA_Coeff);

#define sk_blend_to_grblend(X) ((GrGpu::BlendCoeff)(X))

GR_STATIC_ASSERT((int)SkPath::kMove_Verb  == (int)GrPathIter::kMove_Command);
GR_STATIC_ASSERT((int)SkPath::kLine_Verb  == (int)GrPathIter::kLine_Command);
GR_STATIC_ASSERT((int)SkPath::kQuad_Verb  == (int)GrPathIter::kQuadratic_Command);
GR_STATIC_ASSERT((int)SkPath::kCubic_Verb == (int)GrPathIter::kCubic_Command);
GR_STATIC_ASSERT((int)SkPath::kClose_Verb == (int)GrPathIter::kClose_Command);
GR_STATIC_ASSERT((int)SkPath::kDone_Verb  == (int)GrPathIter::kEnd_Command);

#define sk_path_verb_to_gr_path_command(X) ((GrPathIter::Command)(X))

///////////////////////////////////////////////////////////////////////////////

#include "SkColorPriv.h"

static inline GrRect Sk2Gr(const SkRect& src) {
    return GrRect(SkScalarToGrScalar(src.fLeft),
                  SkScalarToGrScalar(src.fTop),
                  SkScalarToGrScalar(src.fRight),
                  SkScalarToGrScalar(src.fBottom));
}

class SkGr {
public:
    static inline SkIRect& SetIRect(SkIRect* dst, const GrIRect& src) {
        GR_STATIC_ASSERT(sizeof(*dst) == sizeof(src));
        memcpy(dst, &src, sizeof(*dst));
        return *dst;
    }

    static inline GrIRect& SetIRect(GrIRect* dst, const SkIRect& src) {
        GR_STATIC_ASSERT(sizeof(*dst) == sizeof(src));
        memcpy(dst, &src, sizeof(*dst));
        return *dst;
    }

    /**
     *  Convert the SkBitmap::Config to the corresponding PixelConfig, or
     *  kUnknown_PixelConfig if the conversion cannot be done.
     */
    static GrTexture::PixelConfig BitmapConfig2PixelConfig(SkBitmap::Config,
                                                        bool isOpaque);

    static GrTexture::PixelConfig Bitmap2PixelConfig(const SkBitmap& bm) {
        return BitmapConfig2PixelConfig(bm.config(), bm.isOpaque());
    }

    static void SkMatrix2GrMatrix(const SkMatrix& m, GrMatrix* g) {
        g->setAll(SkScalarToGrScalar(m[0]),
                  SkScalarToGrScalar(m[1]),
                  SkScalarToGrScalar(m[2]),
                  SkScalarToGrScalar(m[3]),
                  SkScalarToGrScalar(m[4]),
                  SkScalarToGrScalar(m[5]),
                  SkScalarToGrScalar(m[6]),
                  SkScalarToGrScalar(m[7]),
                  SkScalarToGrScalar(m[8]));
    }

    static GrColor SkColor2GrColor(SkColor c) {
        SkPMColor pm = SkPreMultiplyColor(c);
        unsigned r = SkGetPackedR32(pm);
        unsigned g = SkGetPackedG32(pm);
        unsigned b = SkGetPackedB32(pm);
        unsigned a = SkGetPackedA32(pm);
        return GrColorPackRGBA(r, g, b, a);
    }

    /**
     *  This abandons all texture caches (for bitmaps and text) associated with
     *  the gpu, and frees any associated skia caches. It differs from
     *  deleteAllTextures in that it assumes that the gpu has lots its context,
     *  and thus the associated HW textures are no longer valid
     */
    static void AbandonAllTextures(GrContext*);
};

////////////////////////////////////////////////////////////////////////////////
// Classes

class SkGrPathIter : public GrPathIter {
public:
    SkGrPathIter(const SkPath& path) : fIter(path, false), fPath(path) {}
    virtual Command next(GrPoint pts[]);
    virtual Command next();
    virtual void rewind();
    virtual ConvexHint hint() const;
private:

#if !SK_SCALAR_IS_GR_SCALAR
    SkPoint             fPoints[4];
#endif
    SkPath::Iter        fIter;
    const SkPath&       fPath;
};

class SkGrClipIterator : public GrClipIterator {
public:
    void reset(const SkRegion& clip) {
        fIter.reset(clip);
        this->invalidateBoundsCache();
    }

    // overrides

    virtual bool isDone() { return fIter.done(); }
    virtual void getRect(GrIRect* rect) {
        SkGr::SetIRect(rect, fIter.rect());
    }
    virtual void next() { fIter.next(); }
    virtual void rewind() { fIter.rewind(); }
    virtual void computeBounds(GrIRect* bounds);

private:
    SkRegion::Iterator fIter;
};

class SkGlyphCache;

class SkGrFontScaler : public GrFontScaler {
public:
    explicit SkGrFontScaler(SkGlyphCache* strike);
    virtual ~SkGrFontScaler();

    // overrides
    virtual const GrKey* getKey();
    virtual bool getPackedGlyphBounds(GrGlyph::PackedID, GrIRect* bounds);
    virtual bool getPackedGlyphImage(GrGlyph::PackedID, int width, int height,
                                     int rowBytes, void* image);
    virtual bool getGlyphPath(uint16_t glyphID, GrPath*);

private:
    SkGlyphCache* fStrike;
    GrKey*  fKey;
//    DECLARE_INSTANCE_COUNTER(SkGrFontScaler);
};

////////////////////////////////////////////////////////////////////////////////
// Helper functions

GrTextureEntry* sk_gr_create_bitmap_texture(GrContext* ctx,
                                            GrTextureKey* key,
                                            const GrSamplerState& sampler,
                                            const SkBitmap& bitmap);


#endif
