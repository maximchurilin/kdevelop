/* KDevelop CMake Support
 *
 * Copyright 2006 Matt Rogers <mattr@kde.org>
 * Copyright 2008 Aleix Pol <aleixpol@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#ifndef CMAKEASTTEST_H
#define CMAKEASTTEST_H

#include <QtTest/QtTest>

class CMakeAstTest : public QObject
{
    Q_OBJECT
public:
    CMakeAstTest() {}
    virtual ~CMakeAstTest() {}

private slots:
    void testAddExecutableGoodParse();
    void testAddExecutableGoodParse_data();
    void testAddExecutableBadParse();
    void testAddExecutableBadParse_data();
    void testAddLibraryGoodParse();
    void testAddLibraryGoodParse_data();
    void testAddLibraryBadParse();
    void testAddLibraryBadParse_data();
    void testAddSubdirectoryGoodParse();
    void testAddSubdirectoryGoodParse_data();
    void testAddSubdirectoryBadParse();
    void testAddSubdirectoryBadParse_data();
    void testAddTestGoodParse();
    void testAddTestGoodParse_data();
    void testAddTestBadParse();
    void testAddTestBadParse_data();
    void testAuxSourceDirectoryGoodParse();
    void testAuxSourceDirectoryGoodParse_data();
    void testAuxSourceDirectoryBadParse();
    void testAuxSourceDirectoryBadParse_data();
    void testBreakGoodParse();
    void testBreakGoodParse_data();
    void testBreakBadParse();
    void testBreakBadParse_data();
    void testBuildCommandGoodParse();
    void testBuildCommandGoodParse_data();
    void testBuildCommandBadParse();
    void testBuildCommandBadParse_data();
    void testBuildNameGoodParse();
    void testBuildNameGoodParse_data();
    void testBuildNameBadParse();
    void testBuildNameBadParse_data();
    void testCMakeMinimumRequiredGoodParse();
    void testCMakeMinimumRequiredGoodParse_data();
    void testCMakeMinimumRequiredBadParse();
    void testCMakeMinimumRequiredBadParse_data();
    void testCMakePolicyGoodParse();
    void testCMakePolicyGoodParse_data();
    void testCMakePolicyBadParse();
    void testCMakePolicyBadParse_data();
    void testConfigureFileGoodParse();
    void testConfigureFileGoodParse_data();
    void testConfigureFileBadParse();
    void testConfigureFileBadParse_data();
    void testCreateTestSourcelistGoodParse();
    void testCreateTestSourcelistGoodParse_data();
    void testCreateTestSourcelistBadParse();
    void testCreateTestSourcelistBadParse_data();
    void testEnableLanguageGoodParse();
    void testEnableLanguageGoodParse_data();
    void testEnableLanguageBadParse();
    void testEnableLanguageBadParse_data();
    void testEnableTestingGoodParse();
    void testEnableTestingGoodParse_data();
    void testEnableTestingBadParse();
    void testEnableTestingBadParse_data();
    void testExecProgramGoodParse();
    void testExecProgramGoodParse_data();
    void testExecProgramBadParse();
    void testExecProgramBadParse_data();
    void testExecuteProcessGoodParse();
    void testExecuteProcessGoodParse_data();
    void testExecuteProcessBadParse();
    void testExecuteProcessBadParse_data();
    void testExportGoodParse();
    void testExportGoodParse_data();
    void testExportBadParse();
    void testExportBadParse_data();
    void testExportLibraryDepsGoodParse();
    void testExportLibraryDepsGoodParse_data();
    void testExportLibraryDepsBadParse();
    void testExportLibraryDepsBadParse_data();
    void testFileGoodParse();
    void testFileGoodParse_data();
    void testFileBadParse();
    void testFileBadParse_data();
    void testFindFileGoodParse();
    void testFindFileGoodParse_data();
    void testFindFileBadParse();
    void testFindFileBadParse_data();
    void testFindLibraryGoodParse();
    void testFindLibraryGoodParse_data();
    void testFindLibraryBadParse();
    void testFindLibraryBadParse_data();
    void testFindPackageGoodParse();
    void testFindPackageGoodParse_data();
    void testFindPackageBadParse();
    void testFindPackageBadParse_data();
    void testFindPathGoodParse();
    void testFindPathGoodParse_data();
    void testFindPathBadParse();
    void testFindPathBadParse_data();
    void testFindProgramGoodParse();
    void testFindProgramGoodParse_data();
    void testFindProgramBadParse();
    void testFindProgramBadParse_data();
    void testFltkWrapUiGoodParse();
    void testFltkWrapUiGoodParse_data();
    void testFltkWrapUiBadParse();
    void testFltkWrapUiBadParse_data();
    void testForeachGoodParse();
    void testForeachGoodParse_data();
    void testForeachBadParse();
    void testForeachBadParse_data();
    void testGetCMakePropertyGoodParse();
    void testGetCMakePropertyGoodParse_data();
    void testGetCMakePropertyBadParse();
    void testGetCMakePropertyBadParse_data();
    void testGetDirPropertyGoodParse();
    void testGetDirPropertyGoodParse_data();
    void testGetDirPropertyBadParse();
    void testGetDirPropertyBadParse_data();
    void testGetFilenameComponentGoodParse();
    void testGetFilenameComponentGoodParse_data();
    void testGetFilenameComponentBadParse();
    void testGetFilenameComponentBadParse_data();
    void testGetPropertyGoodParse();
    void testGetPropertyGoodParse_data();
    void testGetPropertyBadParse();
    void testGetPropertyBadParse_data();
    void testGetSourceFilePropGoodParse();
    void testGetSourceFilePropGoodParse_data();
    void testGetSourceFilePropBadParse();
    void testGetSourceFilePropBadParse_data();
    void testGetTargetPropGoodParse();
    void testGetTargetPropGoodParse_data();
    void testGetTargetPropBadParse();
    void testGetTargetPropBadParse_data();
    void testGetTestPropGoodParse();
    void testGetTestPropGoodParse_data();
    void testGetTestPropBadParse();
    void testGetTestPropBadParse_data();
    void testIfGoodParse();
    void testIfGoodParse_data();
    void testIfBadParse();
    void testIfBadParse_data();
    void testIncludeGoodParse();
    void testIncludeGoodParse_data();
    void testIncludeBadParse();
    void testIncludeBadParse_data();
    void testIncludeDirectoriesGoodParse();
    void testIncludeDirectoriesGoodParse_data();
    void testIncludeDirectoriesBadParse();
    void testIncludeDirectoriesBadParse_data();
    void testIncludeExternalMsProjectGoodParse();
    void testIncludeExternalMsProjectGoodParse_data();
    void testIncludeExternalMsProjectBadParse();
    void testIncludeExternalMsProjectBadParse_data();
    void testIncludeRegularExpressionGoodParse();
    void testIncludeRegularExpressionGoodParse_data();
    void testIncludeRegularExpressionBadParse();
    void testIncludeRegularExpressionBadParse_data();
    void testInstallGoodParse();
    void testInstallGoodParse_data();
    void testInstallBadParse();
    void testInstallBadParse_data();
    void testInstallFilesGoodParse();
    void testInstallFilesGoodParse_data();
    void testInstallFilesBadParse();
    void testInstallFilesBadParse_data();
    void testInstallProgramsGoodParse();
    void testInstallProgramsGoodParse_data();
    void testInstallProgramsBadParse();
    void testInstallProgramsBadParse_data();
    void testInstallTargetsGoodParse();
    void testInstallTargetsGoodParse_data();
    void testInstallTargetsBadParse();
    void testInstallTargetsBadParse_data();
    void testLinkDirectoriesGoodParse();
    void testLinkDirectoriesGoodParse_data();
    void testLinkDirectoriesBadParse();
    void testLinkDirectoriesBadParse_data();
    void testLinkLibrariesGoodParse();
    void testLinkLibrariesGoodParse_data();
    void testLinkLibrariesBadParse();
    void testLinkLibrariesBadParse_data();
    void testListGoodParse();
    void testListGoodParse_data();
    void testListBadParse();
    void testListBadParse_data();
    void testLoadCacheGoodParse();
    void testLoadCacheGoodParse_data();
    void testLoadCacheBadParse();
    void testLoadCacheBadParse_data();
    void testLoadCommandGoodParse();
    void testLoadCommandGoodParse_data();
    void testLoadCommandBadParse();
    void testLoadCommandBadParse_data();
    void testMacroGoodParse();
    void testMacroGoodParse_data();
    void testMacroBadParse();
    void testMacroBadParse_data();
    void testFunctionGoodParse();
    void testFunctionGoodParse_data();
    void testFunctionBadParse();
    void testFunctionBadParse_data();
    void testMakeDirectoryGoodParse();
    void testMakeDirectoryGoodParse_data();
    void testMakeDirectoryBadParse();
    void testMakeDirectoryBadParse_data();
    void testMarkAsAdvancedGoodParse();
    void testMarkAsAdvancedGoodParse_data();
    void testMarkAsAdvancedBadParse();
    void testMarkAsAdvancedBadParse_data();
    void testMathGoodParse();
    void testMathGoodParse_data();
    void testMathBadParse();
    void testMathBadParse_data();
    void testMessageGoodParse();
    void testMessageGoodParse_data();
    void testMessageBadParse();
    void testMessageBadParse_data();
    void testOptionGoodParse();
    void testOptionGoodParse_data();
    void testOptionBadParse();
    void testOptionBadParse_data();
    void testOutputRequiredFilesGoodParse();
    void testOutputRequiredFilesGoodParse_data();
    void testOutputRequiredFilesBadParse();
    void testOutputRequiredFilesBadParse_data();
    void testProjectGoodParse();
    void testProjectGoodParse_data();
    void testProjectBadParse();
    void testProjectBadParse_data();
    void testQtWrapCppGoodParse();
    void testQtWrapCppGoodParse_data();
    void testQtWrapCppBadParse();
    void testQtWrapCppBadParse_data();
    void testQtWrapUiGoodParse();
    void testQtWrapUiGoodParse_data();
    void testQtWrapUiBadParse();
    void testQtWrapUiBadParse_data();
    void testRemoveGoodParse();
    void testRemoveGoodParse_data();
    void testRemoveBadParse();
    void testRemoveBadParse_data();
    void testRemoveDefinitionsGoodParse();
    void testRemoveDefinitionsGoodParse_data();
    void testRemoveDefinitionsBadParse();
    void testRemoveDefinitionsBadParse_data();
    void testReturnGoodParse();
    void testReturnGoodParse_data();
    void testReturnBadParse();
    void testReturnBadParse_data();
    void testSeparateArgumentsGoodParse();
    void testSeparateArgumentsGoodParse_data();
    void testSeparateArgumentsBadParse();
    void testSeparateArgumentsBadParse_data();
    void testSetGoodParse();
    void testSetGoodParse_data();
    void testSetBadParse();
    void testSetBadParse_data();
    void testSetDirectoryPropsGoodParse();
    void testSetDirectoryPropsGoodParse_data();
    void testSetDirectoryPropsBadParse();
    void testSetDirectoryPropsBadParse_data();
    void testSetPropertyGoodParse();
    void testSetPropertyGoodParse_data();
    void testSetPropertyBadParse();
    void testSetPropertyBadParse_data();
    void testSetSourceFilesPropsGoodParse();
    void testSetSourceFilesPropsGoodParse_data();
    void testSetSourceFilesPropsBadParse();
    void testSetSourceFilesPropsBadParse_data();
    void testSetTargetPropsGoodParse();
    void testSetTargetPropsGoodParse_data();
    void testSetTargetPropsBadParse();
    void testSetTargetPropsBadParse_data();
    void testSetTestsPropsGoodParse();
    void testSetTestsPropsGoodParse_data();
    void testSetTestsPropsBadParse();
    void testSetTestsPropsBadParse_data();
    void testSiteNameGoodParse();
    void testSiteNameGoodParse_data();
    void testSiteNameBadParse();
    void testSiteNameBadParse_data();
    void testSourceGroupGoodParse();
    void testSourceGroupGoodParse_data();
    void testSourceGroupBadParse();
    void testSourceGroupBadParse_data();
    void testStringGoodParse();
    void testStringGoodParse_data();
    void testStringBadParse();
    void testStringBadParse_data();
    void testSubdirDependsGoodParse();
    void testSubdirDependsGoodParse_data();
    void testSubdirDependsBadParse();
    void testSubdirDependsBadParse_data();
    void testSubdirsGoodParse();
    void testSubdirsGoodParse_data();
    void testSubdirsBadParse();
    void testSubdirsBadParse_data();
    void testTargetLinkLibrariesGoodParse();
    void testTargetLinkLibrariesGoodParse_data();
    void testTargetLinkLibrariesBadParse();
    void testTargetLinkLibrariesBadParse_data();
    void testTryCompileGoodParse();
    void testTryCompileGoodParse_data();
    void testTryCompileBadParse();
    void testTryCompileBadParse_data();
    void testTryRunGoodParse();
    void testTryRunGoodParse_data();
    void testTryRunBadParse();
    void testTryRunBadParse_data();
    void testUseMangledMesaGoodParse();
    void testUseMangledMesaGoodParse_data();
    void testUseMangledMesaBadParse();
    void testUseMangledMesaBadParse_data();
    void testUtilitySourceGoodParse();
    void testUtilitySourceGoodParse_data();
    void testUtilitySourceBadParse();
    void testUtilitySourceBadParse_data();
    void testVariableRequiresGoodParse();
    void testVariableRequiresGoodParse_data();
    void testVariableRequiresBadParse();
    void testVariableRequiresBadParse_data();
    void testVtkMakeInstantiatorGoodParse();
    void testVtkMakeInstantiatorGoodParse_data();
    void testVtkMakeInstantiatorBadParse();
    void testVtkMakeInstantiatorBadParse_data();
    void testVtkWrapJavaGoodParse();
    void testVtkWrapJavaGoodParse_data();
    void testVtkWrapJavaBadParse();
    void testVtkWrapJavaBadParse_data();
    void testVtkWrapPythonGoodParse();
    void testVtkWrapPythonGoodParse_data();
    void testVtkWrapPythonBadParse();
    void testVtkWrapPythonBadParse_data();
    void testVtkWrapTclGoodParse();
    void testVtkWrapTclGoodParse_data();
    void testVtkWrapTclBadParse();
    void testVtkWrapTclBadParse_data();
    void testWhileGoodParse();
    void testWhileGoodParse_data();
    void testWhileBadParse();
    void testWhileBadParse_data();
    void testWriteFileGoodParse();
    void testWriteFileGoodParse_data();
    void testWriteFileBadParse();
    void testWriteFileBadParse_data();
};

#endif
