//--------------------------------------------------------------------------------------
// File: Animation.cpp
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//
// http://go.microsoft.com/fwlink/?LinkId=248929
//--------------------------------------------------------------------------------------

#include "pch.h"

#include "Animation.h"
#include "PlatformHelpers.h"

using namespace DirectX;

//======================================================================================
// Skeleton
//======================================================================================

class Skeleton::Impl
{
public:
    Impl( _In_reads_(count) const Bone* bones, _In_ size_t count )
    {
        if ( !bones || !count )
            throw std::exception("invalid arguments");

        mCount = count;
        mParents.reset( new uint32_t[count] );
        mTransforms.reset( reinterpret_cast<XMMATRIX*>( _aligned_malloc( sizeof(XMMATRIX) * count, 16 ) ) );

        auto parentArray = mParents.get();
        XMMATRIX* matrixArray = mTransforms.get();

        for( unsigned int j = 0; j < count; ++j )
        {
            if ( bones[j].parent != uint32_t(-1) )
            {
                if ( bones[j].parent >= j )
                {
                    // Bones array should be sorted so that parents come before children. If not, we throw an exception
                    throw std::exception("bones are not sorted or parent is out of range");
                }
            }

            parentArray[j] = bones[j].parent;
            matrixArray[j] = XMLoadFloat4x4( &bones[j].transform );
            mNames[ bones[j].name ] = j;
        }
    }

    void CopyAbsoluteBoneTransformsTo( _Out_writes_(count) XMMATRIX* dest, _In_ size_t count ) const
    {
        if ( count > mCount )
            throw std::out_of_range("count is out of range");

        auto parentArray = mParents.get();
        const XMMATRIX* matrixArray = mTransforms.get();

        for( size_t j = 0; j < count; ++j )
        {
            uint32_t parent = parentArray[j];

            if ( parent == uint32_t(-1) )
            {
                dest[j] = matrixArray[j];
            }
            else
            {
                dest[j] = XMMatrixMultiply( matrixArray[j], dest[ parent ] );
            }
        }
    }

    void CopyBoneTransformsTo( _Out_writes_(count) XMMATRIX* dest, _In_ size_t count ) const
    {
        if ( count > mCount )
            throw std::out_of_range("count is out of range");

        const XMMATRIX* matrixArray = mTransforms.get();

        for( size_t j = 0; j < count; ++j )
        {
            dest[j] = matrixArray[j];
        }
    }

    void CopyBoneTransformsFrom( _In_reads_(count) const XMMATRIX* source, _In_ size_t count )
    {
        if ( count > mCount )
            throw std::out_of_range("count is out of range");

        XMMATRIX* matrixArray = mTransforms.get();

        for( size_t j = 0; j < count; ++j )
        {
            matrixArray[j] = source[j];
        }
    }

    int FindBone( _In_z_ const wchar_t* name ) const
    {
        auto it = mNames.find( name );
        return ( it == mNames.end() ) ? -1 : it->second;
    }

private:
    size_t                                      mCount;
    std::unique_ptr<uint32_t>                   mParents;
    std::unique_ptr<XMMATRIX, aligned_deleter>  mTransforms;
    std::map<std::wstring, uint32_t>            mNames;
};


//--------------------------------------------------------------------------------------
_Use_decl_annotations_
Skeleton::Skeleton( const Bone* bones, size_t count )
    : pImpl( new Impl( bones, count ) )
{
}


Skeleton::~Skeleton()
{
}


//--------------------------------------------------------------------------------------
_Use_decl_annotations_
void Skeleton::CopyAbsoluteBoneTransformsTo( XMMATRIX* dest, size_t count ) const
{
    pImpl->CopyAbsoluteBoneTransformsTo( dest, count );
}


//--------------------------------------------------------------------------------------
_Use_decl_annotations_
void Skeleton::CopyBoneTransformsTo( XMMATRIX* dest, size_t count ) const
{
    pImpl->CopyBoneTransformsTo( dest, count );
}


//--------------------------------------------------------------------------------------
_Use_decl_annotations_
void Skeleton::CopyBoneTransformsFrom( const XMMATRIX* source, size_t count )
{
    pImpl->CopyBoneTransformsFrom( source, count );
}


//--------------------------------------------------------------------------------------
_Use_decl_annotations_
int Skeleton::FindBone( const wchar_t* name ) const
{
    return pImpl->FindBone( name );
}



//======================================================================================
// AnimationMatrix
//======================================================================================

class AnimationMatrix::Impl
{
public:
};


//--------------------------------------------------------------------------------------
_Use_decl_annotations_
AnimationMatrix::AnimationMatrix( const Bone* bones, size_t count )
    : Skeleton( bones, count )
{
}


AnimationMatrix::~AnimationMatrix()
{
}


//--------------------------------------------------------------------------------------
_Use_decl_annotations_
void AnimationMatrix::Evaluate( int clip, float time, bool periodic, XMMATRIX* dest, size_t count ) const
{
    UNREFERENCED_PARAMETER(clip);
    UNREFERENCED_PARAMETER(time);
    UNREFERENCED_PARAMETER(periodic);
    UNREFERENCED_PARAMETER(dest);
    UNREFERENCED_PARAMETER(count);
    // TODO -
}


//--------------------------------------------------------------------------------------
int AnimationMatrix::GetClipCount() const
{
    // TODO -
    return 0;
}


//--------------------------------------------------------------------------------------
_Use_decl_annotations_
int AnimationMatrix::FindClip( const wchar_t* name ) const
{
    UNREFERENCED_PARAMETER(name);
    // TODO -
    return -1;
}


//--------------------------------------------------------------------------------------
_Use_decl_annotations_
void AnimationMatrix::AddClip( const wchar_t* name, float start, float end, const Key* keys, size_t count )
{
    UNREFERENCED_PARAMETER(name);
    UNREFERENCED_PARAMETER(start);
    UNREFERENCED_PARAMETER(end);
    UNREFERENCED_PARAMETER(keys);
    UNREFERENCED_PARAMETER(count);
    // TODO -
}


//--------------------------------------------------------------------------------------
_Use_decl_annotations_
std::unique_ptr<AnimationMatrix> AnimationMatrix::Create( const Bone* bones, size_t count )
{
    return std::unique_ptr<AnimationMatrix>( new AnimationMatrix(bones, count) );
}



//======================================================================================
// AnimationSRT
//======================================================================================

class AnimationSRT::Impl
{
public:
    // TODO -
};


//--------------------------------------------------------------------------------------
_Use_decl_annotations_
AnimationSRT::AnimationSRT( const Bone* bones, size_t count )
    : Skeleton( bones, count )
{
}


AnimationSRT::~AnimationSRT()
{
}


//--------------------------------------------------------------------------------------
_Use_decl_annotations_
void AnimationSRT::Evaluate( int clip, float time, bool periodic, XMMATRIX* dest, size_t count ) const
{
    UNREFERENCED_PARAMETER(clip);
    UNREFERENCED_PARAMETER(time);
    UNREFERENCED_PARAMETER(periodic);
    UNREFERENCED_PARAMETER(dest);
    UNREFERENCED_PARAMETER(count);
    // TODO -
}


//--------------------------------------------------------------------------------------
int AnimationSRT::GetClipCount() const
{
    // TODO -
    return 0;
}


//--------------------------------------------------------------------------------------
_Use_decl_annotations_
int AnimationSRT::FindClip( const wchar_t* name ) const
{
    UNREFERENCED_PARAMETER(name);
    // TODO -
    return -1;
}


//--------------------------------------------------------------------------------------
_Use_decl_annotations_
std::unique_ptr<AnimationSRT> AnimationSRT::Create( const Bone* bones, size_t count )
{
    return std::unique_ptr<AnimationSRT>( new AnimationSRT(bones, count) );
}
