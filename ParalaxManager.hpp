#pragma once

using namespace System::Drawing;

ref class ParalaxManager {
	private:
		Bitmap^ background;
		Bitmap^ midground1;
		Bitmap^ midground2;
		Bitmap^ foreground;

		float strchFctrX = 2;	//Stretch Factor
		float strchFctrY = 1;	//Stretch Factor

		int scrollSpeed = 1;
		int scrollOffset;

		float backX;
		float mid1X;
		float mid2X;
		float foreX;

		float backFctr = 1;
		float mid1Fctr = 2;
		float mid2Fctr = 3;
		float foreFctr = 4;

		void update(int lmtX) {
			backX += -scrollSpeed * backFctr;
			mid1X += -scrollSpeed * mid1Fctr;
			mid2X += -scrollSpeed * mid2Fctr;
			foreX += -scrollSpeed * foreFctr;

			if (backX + (lmtX * strchFctrX) <= 0) {
				backX = 0;
			}
			if (mid1X + (lmtX * strchFctrX) <= 0) {
				mid1X = 0;
			}
			if (mid2X + (lmtX * strchFctrX) <= 0) {
				mid2X = 0;
			}
			if (foreX + (lmtX * strchFctrX) <= 0) {
				foreX = 0;
			}
		}

public:
	ParalaxManager(int bckgrnd, int scrl) {	//El numero del background a cargar
		if (bckgrnd == 1) {
			init_1();
			scrollSpeed = scrl;
		}
	}
	~ParalaxManager() {
		if (background) { delete background; }
		if (midground1) { delete midground1; }
		if (midground2) { delete midground2; }
		if (foreground) { delete foreground; }
	}

	void init_1() {
		background = gcnew Bitmap("Imagenes/paralax/citySky.png");
		midground1 = gcnew Bitmap("Imagenes/paralax/cityMountains.png");
		midground2 = gcnew Bitmap("Imagenes/paralax/cityBuildings.png");
		foreground = gcnew Bitmap("Imagenes/paralax/cityBush.png");
	}

	void draw(BufferedGraphics^ buffer) {
		update(buffer->Graphics->VisibleClipBounds.Width);
		
		buffer->Graphics->DrawImage(background, int(backX), 0,
			int(buffer->Graphics->VisibleClipBounds.Width * strchFctrX),
			int(buffer->Graphics->VisibleClipBounds.Height * strchFctrY));
		buffer->Graphics->DrawImage(background, int(backX + (buffer->Graphics->VisibleClipBounds.Width * strchFctrX)), 0,
			int(buffer->Graphics->VisibleClipBounds.Width * strchFctrX),
			int(buffer->Graphics->VisibleClipBounds.Height * strchFctrY));

		buffer->Graphics->DrawImage(midground1, int(mid1X), 0,
			int(buffer->Graphics->VisibleClipBounds.Width * strchFctrX),
			int(buffer->Graphics->VisibleClipBounds.Height * strchFctrY));
		buffer->Graphics->DrawImage(midground1, int(mid1X + (buffer->Graphics->VisibleClipBounds.Width * strchFctrX)), 0,
			int(buffer->Graphics->VisibleClipBounds.Width * strchFctrX),
			int(buffer->Graphics->VisibleClipBounds.Height * strchFctrY));

		buffer->Graphics->DrawImage(midground2, int(mid2X), 0,
			int(buffer->Graphics->VisibleClipBounds.Width * strchFctrX),
			int(buffer->Graphics->VisibleClipBounds.Height * strchFctrY));
		buffer->Graphics->DrawImage(midground2, int(mid2X + (buffer->Graphics->VisibleClipBounds.Width * strchFctrX)), 0,
			int(buffer->Graphics->VisibleClipBounds.Width * strchFctrX),
			int(buffer->Graphics->VisibleClipBounds.Height * strchFctrY));

		buffer->Graphics->DrawImage(foreground, int(foreX), 0,		//NO necesita doble dibujado pq no nota xd
			int(buffer->Graphics->VisibleClipBounds.Width * strchFctrX),
			int(buffer->Graphics->VisibleClipBounds.Height * strchFctrY));


		//buffer->Graphics->DrawString(mid2X.ToString(), gcnew System::Drawing::Font("Arial", 16), Brushes::Black, 10, 10);
		buffer->Graphics->DrawString(int(mid2X + (buffer->Graphics->VisibleClipBounds.Width * strchFctrX)).ToString(), gcnew System::Drawing::Font("Arial", 16), Brushes::Black, 10, 30);
	}
};