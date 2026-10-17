#pragma once

#include "Engine.h"
#include "Asset.h"

struct  FMeshSlot
{
	FIndexBuffer IndexBuffer;
	TSharedPtr<class CMaterial> Material;
};


class CMesh abstract : public CAsset
{
public:
	CMesh();
	virtual ~CMesh();
	virtual bool CreateMesh(void* VertexData, int Size, int Count, D3D11_USAGE VertexUsage, D3D11_PRIMITIVE_TOPOLOGY Primitiv, void* IndexData = nullptr, int IndexSize = 0, int IndexCount = 0, DXGI_FORMAT Fmt = DXGI_FORMAT_UNKNOWN, D3D11_USAGE IndexUsage = D3D11_USAGE_DEFAULT);
	bool CreateBuffer(ID3D11Buffer** Buffer, D3D11_BIND_FLAG Flag, void* Data, int Size, int Count, D3D11_USAGE Usage);
	void Render();
	void Render(int SlotIndex);


	int GetSlotCount() const { return static_cast<int>(mMeshSlot.size()); }
	const FMeshSlot* GetSlot(int SlotIndex) const { return mMeshSlot[SlotIndex]; }

protected:
	FVertexBuffer mVertexBuffer;
	std::vector<FMeshSlot*> mMeshSlot;
	D3D11_PRIMITIVE_TOPOLOGY mPrimitive;
};