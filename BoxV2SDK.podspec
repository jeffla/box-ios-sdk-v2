Pod::Spec.new do |s|

  s.name         = "BoxV2SDK"
  s.version      = "0.0.1"
  s.summary      = "The iOS SDK for the Box v2 API."
  s.homepage     = "https://github.com/box/box-ios-sdk-v2"
  # s.screenshots  = "www.example.com/screenshots_1", "www.example.com/screenshots_2"
  s.license      = { :type => 'MIT', :file => 'FILE_LICENSE' }
  s.homepage     = "http://EXAMPLE/Empty"
  # s.screenshots  = "www.example.com/screenshots_1", "www.example.com/screenshots_2"
  s.author       = { "Bozo Clown" => "bozo@clown.com" }

  s.platform     = :ios, '5.0'
  # s.source       = { :git => "https://github.com/box/box-ios-sdk-v2.git", :tag => "v1.1.0-b4" }
  s.source       = { :git => "https://github.com/jeffla/box-ios-sdk-v2.git", :commit => "6ce0cf13f" }
  s.source_files  = 'BoxSDK/*'
  s.exclude_files = "BoxSDK/BoxSDK-Prefix.pch"
  s.resources = "BoxSDKResources/Assets/*.png", "BoxSDKResources/Icons/*.png"
  s.frameworks = 'QuartzCore', 'Security'
end
