# コンピューターグラフィックス最終課題 GitHub　Contribution Visualizer

## 概要

このレポジトリでは2022年春に開講されたコンピューターグラフィックスの授業の最終課題として提出したコードを掲載しています。

このプログラムはGitHubのコントリビューショングラフを3dで可視化するものです。内部のプログラムの流れとしては以下のようになります。

1. GitHubのPersonal Access Tokenを取得し、対象のGitHubユーザーIDの入力を受け付ける
2. Http通信でGitHubにGraphQL形式で対象のユーザーのリクエストを送りその結果を処理する
3. 取得したデータをもとにアニメーションを生成する

## 動かし方

このプログラムを動かすには、[プロジェクトセットアップ](#プロジェクトセットアップ)でプロジェクトを開くか、[x64Release](x64Release)フォルダーをダウンロード・解凍してexeファイルをフォルダー内で実行してください。

## レポート

[課題で提出したレポートはこちら](CG_FinalReport2164027.pdf)

## プロジェクトセットアップ

このプロジェクトはVisual Studioを用いて編集しています。
このプロジェクトではHttp通信を実現するためにライブラリとしてCppRestSDKを用いています。このプロジェクトに変更を加える際はそのセットアップが必要となります。
[VCPKGのセットアップ](https://vcpkg.io/en/getting-started.html)
[VCPKGを用いたCppRestSDKのセットアップ](https://github.com/microsoft/cpprestsdk)

### 開発環境

OS: Windows11
Surface Pro 7+ i7-1165G7