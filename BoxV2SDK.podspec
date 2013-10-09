Pod::Spec.new do |s|

  s.name         = "BoxV2SDK"
  s.version      = "0.0.1"
  s.summary      = "The iOS SDK for the Box v2 API."
  s.homepage     = "https://github.com/box/box-ios-sdk-v2"
  # s.screenshots  = "www.example.com/screenshots_1", "www.example.com/screenshots_2"
  s.license      = { :type => 'MIT', :file => 'LICENSE' }
  s.author       = { "Box iOS SDK Author" => "boxiosskdauthor@box.com" }
  s.platform     = :ios, '5.0'
  s.source       = { :git => "https://github.com/box/box-ios-sdk-v2.git", :tag => "0.0.1" }
  s.source_files  = 'BoxSDK/*', 'BoxSDK/Categories/*', 'BoxSDK/External/ISO8601DateFormatter/*.{h,m}', 'BoxSDK/FolderPicker/*', 'BoxSDK/Models/*', 'BoxSDK/OAuth2/*', 'BoxSDK/Operations/*', 'BoxSDK/QueueManagers/*', 'BoxSDK/RequestBuilders/*', 'BoxSDK/ResourceManagers/*'
  s.exclude_files = "BoxSDK/BoxSDK-Prefix.pch"
  s.resources = "BoxSDKResources/Assets/*.png", "BoxSDKResources/Icons/*.png"
  s.frameworks = 'QuartzCore', 'Security'
  s.requires_arc = true
  s.ios.dependency 'ODRefreshControl', '~> 1.1.0'
end
