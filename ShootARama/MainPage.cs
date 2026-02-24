using System.Numerics;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml;
using Microsoft.Graphics.Canvas.UI.Xaml;
using Microsoft.Graphics.Canvas.UI;
using Microsoft.Graphics.Canvas;
using Windows.System;

namespace ShootARama
{
    public sealed partial class MainPage : Page
    {
        private Vector2 playerPosition = new Vector2(100, 300);
        private Vector2 ballPosition = new Vector2(120, 320);
        private bool isShooting = false;
        private float ballVelocityY = 0;
        private float gravity = 0.5f;
        private bool leftPressed = false;
        private bool rightPressed = false;

        public MainPage()
        {
            this.InitializeComponent();
            var canvas = new CanvasAnimatedControl();
            canvas.Update += Canvas_Update;
            canvas.Draw += Canvas_Draw;
            Window.Current.CoreWindow.KeyDown += CoreWindow_KeyDown;
            Window.Current.CoreWindow.KeyUp += CoreWindow_KeyUp;
            this.Content = canvas;
        }

        private void CoreWindow_KeyDown(Windows.UI.Core.CoreWindow sender, Windows.UI.Core.KeyEventArgs args)
        {
            if (args.VirtualKey == VirtualKey.Left)
                leftPressed = true;
            if (args.VirtualKey == VirtualKey.Right)
                rightPressed = true;
            if (args.VirtualKey == VirtualKey.Space && !isShooting)
            {
                isShooting = true;
                ballVelocityY = -10f;
            }
        }

        private void CoreWindow_KeyUp(Windows.UI.Core.CoreWindow sender, Windows.UI.Core.KeyEventArgs args)
        {
            if (args.VirtualKey == VirtualKey.Left)
                leftPressed = false;
            if (args.VirtualKey == VirtualKey.Right)
                rightPressed = false;
        }

        private void Canvas_Update(ICanvasAnimatedControl sender, CanvasAnimatedUpdateEventArgs args)
        {
            float speed = 4f;
            if (leftPressed)
                playerPosition.X -= speed;
            if (rightPressed)
                playerPosition.X += speed;

            if (!isShooting)
            {
                ballPosition = new Vector2(playerPosition.X + 20, playerPosition.Y + 20);
            }
            else
            {
                ballPosition.Y += ballVelocityY;
                ballVelocityY += gravity;
                if (ballPosition.Y > 320)
                {
                    isShooting = false;
                    ballPosition.Y = 320;
                }
            }
        }

        private void Canvas_Draw(ICanvasAnimatedControl sender, CanvasAnimatedDrawEventArgs args)
        {
            var ds = args.DrawingSession;
            ds.Clear(Windows.UI.Colors.DarkGreen);
            // Draw court
            ds.FillRectangle(0, 350, 800, 50, Windows.UI.Colors.SaddleBrown);
            // Draw player
            ds.FillRectangle(playerPosition.X, playerPosition.Y, 20, 40, Windows.UI.Colors.Blue);
            // Draw ball
            ds.FillCircle(ballPosition, 10, Windows.UI.Colors.Orange);
            // Draw hoop (static)
            ds.FillRectangle(700, 250, 10, 60, Windows.UI.Colors.Red);
            ds.DrawRectangle(710, 270, 30, 5, Windows.UI.Colors.White);
        }
    }
}
