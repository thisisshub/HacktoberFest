[#assign UserService = serviceLocator.findService("com.liferay.portal.kernel.service.UserService") ]

[#assign user = UserService.getCurrentUser() ]

<img src="${ user.getPortraitURL( themeDisplay ) }" />
