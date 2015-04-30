#pragma once

#include "Point.h"
#include "Cmn.h"
#include "IRenderable.h"
#include "Rectangle.h"
#include <vector>

namespace talga
{
	struct Tile
	{
		I32 frame;
		bool solid;
	};

	class Renderer;

	class Map : public IRenderable
	{
	public:
		Map(std::string mapName = "INVALID_MAP_NAME", std::vector<Tile> tileSet = {}, cpAnim sheet = nullptr, const std::vector<I32>& map = {}, I32 width = -1, I32 height = -1, I32 tileWidth = -1, I32 tileHeight = -1);
		Map(const Map& cpy);
		~Map();

		virtual void render(Renderer* renderer, const Camera* camera) const override;

		const Map& operator=(const Map& cpy);

		void updateRects();

		const Tile* TileAt(I32 x, I32 y) const;
		//const Tile& CartToTile(int x, int y);
		Point CartToTile(I32 x, I32 y) const;
		Point TileToCart(I32 x, I32 y) const;
		bool Exists(I32 x, I32 y) const; //nullptr
		bool Solid(I32 x, I32 y) const;
		I32 getTileIndex(I32 x, I32 y) const;

		I32 size() const { return mWidth * mHeight; }
		I32 tileWidth() const { return mTileWidth; }
		I32 tileHeight() const { return mTileHeight; }

		I32 getWidth() const { return mWidth; }
		I32 getHeight() const { return mHeight; }
		I32 getTileHeight() const { return mTileHeight; }
		I32 getTileWidth() const { return mTileWidth; }
		cpAnim getSheet() const { return mSheet; }
		std::string getName() const { return mName; }

		
	protected:
		I32 mTileWidth;
		I32 mTileHeight;

		I32 mHeight;
		I32 mWidth;

		I32 mNumTiles;
		cpAnim mSheet;
		std::vector<Tile> mTileSet;
		std::string mName;
		std::vector<I32> mMap;
		std::vector<Rectangle> mRects;
	};

}