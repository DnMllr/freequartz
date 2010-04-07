__inline VGImageFormat 
QuartzImgFormatToOpenVG(CGColorSpaceRef colorspace)
{
	return VG_lRGBA_8888;
}

int ExtractBppFromImgFmt(VGImageFormat vgImgFmt)
{
//	VG_sRGBX_8888                               =  0,
//    VG_sRGBA_8888                               =  1,
//    VG_sRGBA_8888_PRE                           =  2,
//    VG_sRGB_565                                 =  3,
//    VG_sRGBA_5551                               =  4,
//    VG_sRGBA_4444                               =  5,
//    VG_sL_8                                     =  6,
//    VG_lRGBX_8888                               =  7,
//    VG_lRGBA_8888                               =  8,
//    VG_lRGBA_8888_PRE                           =  9,
//    VG_lL_8                                     = 10,
//    VG_A_8                                      = 11,
//    VG_BW_1                                     = 12,
//#if defined(OPENVG_VERSION_1_1)
//    VG_A_1                                      = 13,
//    VG_A_4                                      = 14,
//#endif
//
//    /* {A,X}RGB channel ordering */
//    VG_sXRGB_8888                               =  0 | (1 << 6),
//    VG_sARGB_8888                               =  1 | (1 << 6),
//    VG_sARGB_8888_PRE                           =  2 | (1 << 6),
//    VG_sARGB_1555                               =  4 | (1 << 6),
//    VG_sARGB_4444                               =  5 | (1 << 6),
//    VG_lXRGB_8888                               =  7 | (1 << 6),
//    VG_lARGB_8888                               =  8 | (1 << 6),
//    VG_lARGB_8888_PRE                           =  9 | (1 << 6),
//
//    /* BGR{A,X} channel ordering */
//    VG_sBGRX_8888                               =  0 | (1 << 7),
//    VG_sBGRA_8888                               =  1 | (1 << 7),
//    VG_sBGRA_8888_PRE                           =  2 | (1 << 7),
//    VG_sBGR_565                                 =  3 | (1 << 7),
//    VG_sBGRA_5551                               =  4 | (1 << 7),
//    VG_sBGRA_4444                               =  5 | (1 << 7),
//    VG_lBGRX_8888                               =  7 | (1 << 7),
//    VG_lBGRA_8888                               =  8 | (1 << 7),
//    VG_lBGRA_8888_PRE                           =  9 | (1 << 7),
//
//    /* {A,X}BGR channel ordering */
//    VG_sXBGR_8888                               =  0 | (1 << 6) | (1 << 7),
//    VG_sABGR_8888                               =  1 | (1 << 6) | (1 << 7),
//    VG_sABGR_8888_PRE                           =  2 | (1 << 6) | (1 << 7),
//    VG_sABGR_1555                               =  4 | (1 << 6) | (1 << 7),
//    VG_sABGR_4444                               =  5 | (1 << 6) | (1 << 7),
//    VG_lXBGR_8888                               =  7 | (1 << 6) | (1 << 7),
//    VG_lABGR_8888                               =  8 | (1 << 6) | (1 << 7),
//    VG_lABGR_8888_PRE                           =  9 | (1 << 6) | (1 << 7),
	return 0;
}

//CGContextRef CGBitmapContextCreate(void *data, size_t width,
//								   size_t height, size_t bitsPerComponent, 
//								   size_t bytesPerRow,
//								   CGColorSpaceRef colorspace, 
//								   CGBitmapInfo bitmapInfo)
//{
//	CGContextRef cxtRef;
//	VGImageFormat vgImgFmt;
//	VGImage vgImg;
//	char nAllocated = 0;
//	
//	if (!width || !height || !bytesPerRow || !colorspace)
//		return NULL;
//
//	/* We create a new CGContext */
//	//cxtRef = CGContextCreate();
//	CHK( cxtRef );
//
//	/* Convert and create a Quartz image format into an OpenVG image format */
//	vgImgFmt = QuartzImgFormatToOpenVG(colorspace);
//	CHK( vgImgFmt < VG_IMAGE_FORMAT_FORCE_SIZE );
//
//	vgImg = vgCreateImage(vgImgFmt, width, height, VG_IMAGE_QUALITY_NONANTIALIASED);
//	CHK( vgImg == VG_NO_ERROR );
//
//	/* If caller pass a NULL buffer we allocate for him */
//	if (!data)  {
//		data = malloc(bytesPerRow * height);
//		CHK( data );
//		nAllocated = 1;
//	}
//	
//	vgGetImageSubData(vgImg, data, bytesPerRow, vgImgFmt,0,0,width, height);
//	
//	cxtRef->allocated = nAllocated;
//	cxtRef->data	= data;
//	cxtRef->width	= width;
//	cxtRef->height	= height;
//	cxtRef->bitsPerComponent = bitsPerComponent;
//	cxtRef->bytesPerRow = bytesPerRow;
//	cxtRef->colorspace = colorspace;
//	cxtRef->bitmapInfo = bitmapInfo;
//	
//	cxtRef->vgImgFmt = vgImgFmt;
//	cxtRef->vgImg = vgImg;
//
//	return cxtRef;
//
//Cleanup:
//	if (data && nAllocated) { free(data); }
//	if (cxtRef) { free(cxtRef); }
//	return NULL;
//}