#include "Mesh.h"
#include "AssetManager.h"
#include "Device.h"
#include "Material.h"
#include "MaterialManager.h"

CMesh::CMesh() { mAssetType = EAssetType::Mesh; }

CMesh::~CMesh()
{
	size_t Size = mMeshSlot.size();
	for (size_t i = 0; i < Size; ++i)
	{
		SAFE_DELETE(mMeshSlot[i]);
	}
}

bool CMesh::CreateMesh(void* VertexData, int Size, int Count, D3D11_USAGE VertexUsage, D3D11_PRIMITIVE_TOPOLOGY Primitiv, void* IndexData, int IndexSize, int IndexCount, DXGI_FORMAT Fmt, D3D11_USAGE IndexUsage)
{
	mVertexBuffer.Size = Size;
	mVertexBuffer.Count = Count;
	mVertexBuffer.Data = new char[Size * Count];
	memcpy(mVertexBuffer.Data, VertexData, Size * Count);
	if (!CreateBuffer(&mVertexBuffer.Buffer, D3D11_BIND_VERTEX_BUFFER, VertexData, Size, Count, VertexUsage))
	{
		return false;
	}
	mPrimitive = Primitiv;
	if (IndexData)
	{
		FMeshSlot* Slot = new FMeshSlot;
		Slot->IndexBuffer.Size = IndexSize;
		Slot->IndexBuffer.Count = IndexCount;
		Slot->IndexBuffer.Fmt = Fmt;
		Slot->IndexBuffer.Data = new char[IndexSize * IndexCount];
		memcpy(Slot->IndexBuffer.Data, IndexData, IndexSize * IndexCount);
		if (!CreateBuffer(&Slot->IndexBuffer.Buffer, D3D11_BIND_INDEX_BUFFER, IndexData, IndexSize, IndexCount, IndexUsage))
		{
			SAFE_DELETE(Slot);
			return false;
		}
		Slot->Material = CAssetManager::GetInst()->GetMaterialManager()->FindMaterial("DefaultMaterial");
		mMeshSlot.push_back(Slot);
	}
	return true;
}

bool CMesh::CreateBuffer(ID3D11Buffer** Buffer, D3D11_BIND_FLAG Flag, void* Data, int Size, int Count, D3D11_USAGE Usage)
{
	D3D11_BUFFER_DESC BufferDesc = {};
	BufferDesc.ByteWidth = Size * Count;
	if (Usage == D3D11_USAGE_DYNAMIC)
	{
		BufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	}
	else if (Usage == D3D11_USAGE_STAGING)
	{
		BufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE | D3D11_CPU_ACCESS_READ;
	}
	BufferDesc.BindFlags = Flag;
	BufferDesc.Usage = Usage;
	D3D11_SUBRESOURCE_DATA BufferData = {};
	BufferData.pSysMem = Data;
	if (FAILED(CDevice::GetInst()->GetDevice()->CreateBuffer(&BufferDesc, &BufferData, Buffer)))
	{
		return false;
	}
	return true;
}

void CMesh::Render()
{
	CDevice::GetInst()->GetContext()->IASetPrimitiveTopology(mPrimitive);
	UINT stride = mVertexBuffer.Size;
	UINT Offset = 0;
	CDevice::GetInst()->GetContext()->IASetVertexBuffers(0, 1, &mVertexBuffer.Buffer, &stride, &Offset);
	size_t SlotSize = mMeshSlot.size();
	if (SlotSize > 0)
	{
		for (size_t i = 0; i < SlotSize; ++i)
		{
			CDevice::GetInst()->GetContext()->IASetIndexBuffer(mMeshSlot[i]->IndexBuffer.Buffer, mMeshSlot[i]->IndexBuffer.Fmt, 0); 
			CDevice::GetInst()->GetContext()->DrawIndexed(mMeshSlot[i]->IndexBuffer.Count, 0, 0);
		}
	}
	else
	{ 
		CDevice::GetInst()->GetContext()->IASetIndexBuffer(nullptr, DXGI_FORMAT_UNKNOWN, 0);
		CDevice::GetInst()->GetContext()->Draw(mVertexBuffer.Count, 0);
	}
}

void CMesh::Render(int SlotIndex)
{
	CDevice::GetInst()->GetContext()->IASetPrimitiveTopology(mPrimitive);
	UINT stride = mVertexBuffer.Size;
	UINT Offset = 0;
	CDevice::GetInst()->GetContext()->IASetVertexBuffers(0, 1, &mVertexBuffer.Buffer, &stride, &Offset); 
	size_t SlotSize = mMeshSlot.size();
	if (SlotSize > 0)
	{
		CDevice::GetInst()->GetContext()->IASetIndexBuffer(mMeshSlot[SlotIndex]->IndexBuffer.Buffer, mMeshSlot[SlotIndex]->IndexBuffer.Fmt, 0);
		CDevice::GetInst()->GetContext()->DrawIndexed(mMeshSlot[SlotIndex]->IndexBuffer.Count, 0, 0);

	}
	else
	{
		CDevice::GetInst()->GetContext()->IASetIndexBuffer(nullptr, DXGI_FORMAT_UNKNOWN, 0);
		CDevice::GetInst()->GetContext()->Draw(mVertexBuffer.Count, 0);
	}
}
