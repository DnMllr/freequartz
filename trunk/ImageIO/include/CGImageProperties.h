/****************************************************************************
**
** Copyright (C) 2010 Smartmobili.
** All rights reserved.
** Contact: Smartmobili (contact@smartmobili.com)
**	
** This file is part of the ImageIO module of the freequartz Toolkit.
**
**
** GNU Lesser General Public License Usage	
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements	
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
****************************************************************************/

/* Format-Specific Dictionaries Constants */
CFStringRef kCGImagePropertyTIFFDictionary;
CFStringRef kCGImagePropertyGIFDictionary;
CFStringRef kCGImagePropertyJFIFDictionary;
CFStringRef kCGImagePropertyExifDictionary;
CFStringRef kCGImagePropertyPNGDictionary;
CFStringRef kCGImagePropertyIPTCDictionary;
CFStringRef kCGImagePropertyGPSDictionary;
CFStringRef kCGImagePropertyRawDictionary;
CFStringRef kCGImagePropertyCIFFDictionary;
CFStringRef kCGImageProperty8BIMDictionary;
CFStringRef kCGImagePropertyDNGDictionary;
CFStringRef kCGImagePropertyExifAuxDictionary;

/* Camera maker Constants */
CFStringRef kCGImagePropertyMakerCanonDictionary;
CFStringRef kCGImagePropertyMakerNikonDictionary;
CFStringRef kCGImagePropertyMakerMinoltaDictionary;
CFStringRef kCGImagePropertyMakerFujiDictionary;
CFStringRef kCGImagePropertyMakerOlympusDictionary;
CFStringRef kCGImagePropertyMakerPentaxDictionary;

/* Image Source Container Properties Constants */
CFStringRef kCGImagePropertyFileSize;

/* Individual Image Properties Constants */
CFStringRef kCGImagePropertyDPIHeight;
CFStringRef kCGImagePropertyDPIWidth;
CFStringRef kCGImagePropertyPixelWidth;
CFStringRef kCGImagePropertyPixelHeight;
CFStringRef kCGImagePropertyDepth;
CFStringRef kCGImagePropertyOrientation;
CFStringRef kCGImagePropertyIsFloat;
CFStringRef kCGImagePropertyIsIndexed;
CFStringRef kCGImagePropertyHasAlpha;
CFStringRef kCGImagePropertyColorModel;
CFStringRef kCGImagePropertyProfileName;

/* Color Model Values Constants */
const CFStringRef kCGImagePropertyColorModelRGB;
const CFStringRef kCGImagePropertyColorModelGray;
const CFStringRef kCGImagePropertyColorModelCMYK;
const CFStringRef kCGImagePropertyColorModelLab;

/* EXIF Dictionary Keys Constants */
const CFStringRef kCGImagePropertyExifExposureTime;
const CFStringRef kCGImagePropertyExifFNumber;
const CFStringRef kCGImagePropertyExifExposureProgram;
const CFStringRef kCGImagePropertyExifSpectralSensitivity;
const CFStringRef kCGImagePropertyExifISOSpeedRatings;
const CFStringRef kCGImagePropertyExifOECF;
const CFStringRef kCGImagePropertyExifVersion;
const CFStringRef kCGImagePropertyExifDateTimeOriginal;
const CFStringRef kCGImagePropertyExifDateTimeDigitized;
const CFStringRef kCGImagePropertyExifComponentsConfiguration;
const CFStringRef kCGImagePropertyExifCompressedBitsPerPixel;
const CFStringRef kCGImagePropertyExifShutterSpeedValue;
const CFStringRef kCGImagePropertyExifApertureValue;
const CFStringRef kCGImagePropertyExifBrightnessValue;
const CFStringRef kCGImagePropertyExifExposureBiasValue;
const CFStringRef kCGImagePropertyExifMaxApertureValue;
const CFStringRef kCGImagePropertyExifSubjectDistance;
const CFStringRef kCGImagePropertyExifMeteringMode;
const CFStringRef kCGImagePropertyExifLightSource;
const CFStringRef kCGImagePropertyExifFlash;
const CFStringRef kCGImagePropertyExifFocalLength;
const CFStringRef kCGImagePropertyExifSubjectArea;
const CFStringRef kCGImagePropertyExifMakerNote;
const CFStringRef kCGImagePropertyExifUserComment;
const CFStringRef kCGImagePropertyExifSubsecTime;
const CFStringRef kCGImagePropertyExifSubsecTimeOrginal;
const CFStringRef kCGImagePropertyExifSubsecTimeDigitized;
const CFStringRef kCGImagePropertyExifFlashPixVersion;
const CFStringRef kCGImagePropertyExifColorSpace;
const CFStringRef kCGImagePropertyExifPixelXDimension;
const CFStringRef kCGImagePropertyExifPixelYDimension;
const CFStringRef kCGImagePropertyExifRelatedSoundFile;
const CFStringRef kCGImagePropertyExifFlashEnergy;
const CFStringRef kCGImagePropertyExifSpatialFrequencyResponse;
const CFStringRef kCGImagePropertyExifFocalPlaneXResolution;
const CFStringRef kCGImagePropertyExifFocalPlaneYResolution;
const CFStringRef kCGImagePropertyExifFocalPlaneResolutionUnit;
const CFStringRef kCGImagePropertyExifSubjectLocation;
const CFStringRef kCGImagePropertyExifExposureIndex;
const CFStringRef kCGImagePropertyExifSensingMethod;
const CFStringRef kCGImagePropertyExifFileSource;
const CFStringRef kCGImagePropertyExifSceneType;
const CFStringRef kCGImagePropertyExifCFAPattern;
const CFStringRef kCGImagePropertyExifCustomRendered;
const CFStringRef kCGImagePropertyExifExposureMode;
const CFStringRef kCGImagePropertyExifWhiteBalance;
const CFStringRef kCGImagePropertyExifDigitalZoomRatio;
const CFStringRef kCGImagePropertyExifFocalLenIn35mmFilm;
const CFStringRef kCGImagePropertyExifSceneCaptureType;
const CFStringRef kCGImagePropertyExifGainControl;
const CFStringRef kCGImagePropertyExifContrast;
const CFStringRef kCGImagePropertyExifSaturation;
const CFStringRef kCGImagePropertyExifSharpness;
const CFStringRef kCGImagePropertyExifDeviceSettingDescription;
const CFStringRef kCGImagePropertyExifSubjectDistRange;
const CFStringRef kCGImagePropertyExifImageUniqueID;
const CFStringRef kCGImagePropertyExifGamma;

/* EXIF Auxiliary Dictionary Keys Constants */
const CFStringRef kCGImagePropertyExifAuxLensInfo;
const CFStringRef kCGImagePropertyExifAuxLensModel;
const CFStringRef kCGImagePropertyExifAuxSerialNumber;
const CFStringRef kCGImagePropertyExifAuxLensID;
const CFStringRef kCGImagePropertyExifAuxLensSerialNumber;
const CFStringRef kCGImagePropertyExifAuxImageNumber;
const CFStringRef kCGImagePropertyExifAuxFlashCompensation;
const CFStringRef kCGImagePropertyExifAuxOwnerName;
const CFStringRef kCGImagePropertyExifAuxFirmware;

/* GIF Dictionary Keys Constants */
const CFStringRef kCGImagePropertyGIFLoopCount;
const CFStringRef kCGImagePropertyGIFDelayTime;
const CFStringRef kCGImagePropertyGIFImageColorMap;
const CFStringRef kCGImagePropertyGIFHasGlobalColorMap;

/* GPS Dictionary Keys Constants */
const CFStringRef kCGImagePropertyGPSVersion;
const CFStringRef kCGImagePropertyGPSLatitudeRef;
const CFStringRef kCGImagePropertyGPSLatitude;
const CFStringRef kCGImagePropertyGPSLongitudeRef;
const CFStringRef kCGImagePropertyGPSLongitude;
const CFStringRef kCGImagePropertyGPSAltitudeRef;
const CFStringRef kCGImagePropertyGPSAltitude;
const CFStringRef kCGImagePropertyGPSTimeStamp;
const CFStringRef kCGImagePropertyGPSSatellites;
const CFStringRef kCGImagePropertyGPSStatus;
const CFStringRef kCGImagePropertyGPSMeasureMode;
const CFStringRef kCGImagePropertyGPSDOP;
const CFStringRef kCGImagePropertyGPSSpeedRef;
const CFStringRef kCGImagePropertyGPSSpeed;
const CFStringRef kCGImagePropertyGPSTrackRef;
const CFStringRef kCGImagePropertyGPSTrack;
const CFStringRef kCGImagePropertyGPSImgDirectionRef;
const CFStringRef kCGImagePropertyGPSImgDirection;
const CFStringRef kCGImagePropertyGPSMapDatum;
const CFStringRef kCGImagePropertyGPSDestLatitudeRef;
const CFStringRef kCGImagePropertyGPSDestLatitude;
const CFStringRef kCGImagePropertyGPSDestLongitudeRef;
const CFStringRef kCGImagePropertyGPSDestLongitude;
const CFStringRef kCGImagePropertyGPSDestBearingRef;
const CFStringRef kCGImagePropertyGPSDestBearing;
const CFStringRef kCGImagePropertyGPSDestDistanceRef;
const CFStringRef kCGImagePropertyGPSDestDistance;
const CFStringRef kCGImagePropertyGPSProcessingMethod;
const CFStringRef kCGImagePropertyGPSAreaInformation;
const CFStringRef kCGImagePropertyGPSDateStamp;
const CFStringRef kCGImagePropertyGPSDifferental;

/* IPTC Dictionary Keys Constants */
const CFStringRef kCGImagePropertyIPTCObjectTypeReference;
const CFStringRef kCGImagePropertyIPTCObjectAttributeReference;
const CFStringRef kCGImagePropertyIPTCObjectName;
const CFStringRef kCGImagePropertyIPTCEditStatus;
const CFStringRef kCGImagePropertyIPTCEditorialUpdate;
const CFStringRef kCGImagePropertyIPTCUrgency;
const CFStringRef kCGImagePropertyIPTCSubjectReference;
const CFStringRef kCGImagePropertyIPTCCategory;
const CFStringRef kCGImagePropertyIPTCSupplementalCategory;
const CFStringRef kCGImagePropertyIPTCFixtureIdentifier;
const CFStringRef kCGImagePropertyIPTCKeywords;
const CFStringRef kCGImagePropertyIPTCContentLocationCode;
const CFStringRef kCGImagePropertyIPTCContentLocationName;
const CFStringRef kCGImagePropertyIPTCReleaseDate;
const CFStringRef kCGImagePropertyIPTCReleaseTime;
const CFStringRef kCGImagePropertyIPTCExpirationDate;
const CFStringRef kCGImagePropertyIPTCExpirationTime;
const CFStringRef kCGImagePropertyIPTCSpecialInstructions;
const CFStringRef kCGImagePropertyIPTCActionAdvised;
const CFStringRef kCGImagePropertyIPTCReferenceService;
const CFStringRef kCGImagePropertyIPTCReferenceDate;
const CFStringRef kCGImagePropertyIPTCReferenceNumber;
const CFStringRef kCGImagePropertyIPTCDateCreated;
const CFStringRef kCGImagePropertyIPTCTimeCreated;
const CFStringRef kCGImagePropertyIPTCDigitalCreationDate;
const CFStringRef kCGImagePropertyIPTCDigitalCreationTime;
const CFStringRef kCGImagePropertyIPTCOriginatingProgram;
const CFStringRef kCGImagePropertyIPTCProgramVersion;
const CFStringRef kCGImagePropertyIPTCObjectCycle;
const CFStringRef kCGImagePropertyIPTCByline;
const CFStringRef kCGImagePropertyIPTCBylineTitle;
const CFStringRef kCGImagePropertyIPTCCity;
const CFStringRef kCGImagePropertyIPTCSubLocation;
const CFStringRef kCGImagePropertyIPTCProvinceState;
const CFStringRef kCGImagePropertyIPTCCountryPrimaryLocationCode;
const CFStringRef kCGImagePropertyIPTCCountryPrimaryLocationName;
const CFStringRef kCGImagePropertyIPTCOriginalTransmissionReference;
const CFStringRef kCGImagePropertyIPTCHeadline;
const CFStringRef kCGImagePropertyIPTCCredit;
const CFStringRef kCGImagePropertyIPTCSource;
const CFStringRef kCGImagePropertyIPTCCopyrightNotice;
const CFStringRef kCGImagePropertyIPTCContact;
const CFStringRef kCGImagePropertyIPTCCaptionAbstract;
const CFStringRef kCGImagePropertyIPTCWriterEditor;
const CFStringRef kCGImagePropertyIPTCImageType;
const CFStringRef kCGImagePropertyIPTCImageOrientation;
const CFStringRef kCGImagePropertyIPTCLanguageIdentifier;
const CFStringRef kCGImagePropertyIPTCStarRating;

/* JFIF Dictionary Keys Constants */
const CFStringRef kCGImagePropertyJFIFVersion;
const CFStringRef kCGImagePropertyJFIFXDensity;
const CFStringRef kCGImagePropertyJFIFYDensity;
const CFStringRef kCGImagePropertyJFIFDensityUnit;
const CFStringRef kCGImagePropertyJFIFIsProgressive;

/* PNG Dictionary Keys Constants */
const CFStringRef kCGImagePropertyPNGGamma;
const CFStringRef kCGImagePropertyPNGInterlaceType;
const CFStringRef kCGImagePropertyPNGXPixelsPerMeter;
const CFStringRef kCGImagePropertyPNGYPixelsPerMeter;
const CFStringRef kCGImagePropertyPNGsRGBIntent;
const CFStringRef kCGImagePropertyPNGChromaticities;

/* TIFF Dictionary Keys Constants */
const CFStringRef kCGImagePropertyTIFFCompression;
const CFStringRef kCGImagePropertyTIFFPhotometricInterpretation;
const CFStringRef kCGImagePropertyTIFFDocumentName;
const CFStringRef kCGImagePropertyTIFFImageDescription;
const CFStringRef kCGImagePropertyTIFFMake;
const CFStringRef kCGImagePropertyTIFFModel;
const CFStringRef kCGImagePropertyTIFFOrientation;
const CFStringRef kCGImagePropertyTIFFXResolution;
const CFStringRef kCGImagePropertyTIFFYResolution;
const CFStringRef kCGImagePropertyTIFFResolutionUnit;
const CFStringRef kCGImagePropertyTIFFSoftware;
const CFStringRef kCGImagePropertyTIFFTransferFunction;
const CFStringRef kCGImagePropertyTIFFDateTime;
const CFStringRef kCGImagePropertyTIFFArtist;
const CFStringRef kCGImagePropertyTIFFHostComputer;
const CFStringRef kCGImagePropertyTIFFCopyright;
const CFStringRef kCGImagePropertyTIFFWhitePoint;
const CFStringRef kCGImagePropertyTIFFPrimaryChromaticities;

/* DNG Dictionary Keys Constants */
CFStringRef kCGImagePropertyDNGVersion;
CFStringRef kCGImagePropertyDNGBackwardVersion;
CFStringRef kCGImagePropertyDNGUniqueCameraModel;
CFStringRef kCGImagePropertyDNGLocalizedCameraModel;
CFStringRef kCGImagePropertyDNGCameraSerialNumber;
CFStringRef kCGImagePropertyDNGLensInfo;

/* 8BIM Dictionary Keys Constants */
CFStringRef kCGImageProperty8BIMLayerNames;

/* CIFF Dictionary Keys Constants */
CFStringRef kCGImagePropertyCIFFDescription;
CFStringRef kCGImagePropertyCIFFFirmware;
CFStringRef kCGImagePropertyCIFFOwnerName;
CFStringRef kCGImagePropertyCIFFImageName;
CFStringRef kCGImagePropertyCIFFImageFileName;
CFStringRef kCGImagePropertyCIFFReleaseMethod;
CFStringRef kCGImagePropertyCIFFReleaseTiming;
CFStringRef kCGImagePropertyCIFFRecordID;
CFStringRef kCGImagePropertyCIFFSelfTimingTime;
CFStringRef kCGImagePropertyCIFFCameraSerialNumber;
CFStringRef kCGImagePropertyCIFFImageSerialNumber;
CFStringRef kCGImagePropertyCIFFContinuousDrive;
CFStringRef kCGImagePropertyCIFFFocusMode;
CFStringRef kCGImagePropertyCIFFMeteringMode;
CFStringRef kCGImagePropertyCIFFShootingMode;
CFStringRef kCGImagePropertyCIFFLensMaxMM;
CFStringRef kCGImagePropertyCIFFLensMinMM;
CFStringRef kCGImagePropertyCIFFLensModel;
CFStringRef kCGImagePropertyCIFFWhiteBalanceIndex;
CFStringRef kCGImagePropertyCIFFFlashExposureComp;
CFStringRef kCGImagePropertyCIFFMeasuredEV;

/* Nikon Dictionary Keys Constants */
CFStringRef kCGImagePropertyMakerNikonISOSetting;
CFStringRef kCGImagePropertyMakerNikonColorMode;
CFStringRef kCGImagePropertyMakerNikonQuality;
CFStringRef kCGImagePropertyMakerNikonWhiteBalanceMode;
CFStringRef kCGImagePropertyMakerNikonSharpenMode;
CFStringRef kCGImagePropertyMakerNikonFocusMode;
CFStringRef kCGImagePropertyMakerNikonFlashSetting;
CFStringRef kCGImagePropertyMakerNikonISOSelection;
CFStringRef kCGImagePropertyMakerNikonFlashExposureComp;
CFStringRef kCGImagePropertyMakerNikonImageAdjustment;
CFStringRef kCGImagePropertyMakerNikonLensAdapter;
CFStringRef kCGImagePropertyMakerNikonLensType;
CFStringRef kCGImagePropertyMakerNikonLensInfo;
CFStringRef kCGImagePropertyMakerNikonFocusDistance;
CFStringRef kCGImagePropertyMakerNikonDigitalZoom;
CFStringRef kCGImagePropertyMakerNikonShootingMode;
CFStringRef kCGImagePropertyMakerNikonShutterCount;
CFStringRef kCGImagePropertyMakerNikonCameraSerialNumber;

/* Canon Dictionary Keys Constants */
CFStringRef kCGImagePropertyMakerCanonOwnerName;
CFStringRef kCGImagePropertyMakerCanonCameraSerialNumber;
CFStringRef kCGImagePropertyMakerCanonImageSerialNumber;
CFStringRef kCGImagePropertyMakerCanonFlashExposureComp;
CFStringRef kCGImagePropertyMakerCanonContinuousDrive;
CFStringRef kCGImagePropertyMakerCanonLensModel;
CFStringRef kCGImagePropertyMakerCanonFirmware;
CFStringRef kCGImagePropertyMakerCanonAspectRatioInfo;